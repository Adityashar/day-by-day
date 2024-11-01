#include "common/common.h"
#include <memory>
#include <queue>
#include "exceptions/worker.h"
using namespace std;

/**
 * https://github.com/cppnuts-yt/CppNuts/blob/master/C%2B%2B/Thread%20Pool/thread%20pool%20introduction%20in%20c%2B%2B.cpp
 */


class Task {
    string name;
public:
    Task(const string &_name) {
        name = move(_name);
    }
    string getName() {return name;}

    void run() {
        printf ("Running Task '%s': Doing some work hello hello \n", name.c_str());
        this_thread::sleep_for(chrono::milliseconds(200));
    }
};


/**
 * Thread Pool
 * Maintain a pool K Threads
 * These K threads are then used to perform N Tasks
 */

class ThreadPool {
    vector<thread> workers;
    mutex taskMutex;
    condition_variable cv;

    queue<Task*> tasks;

    int size;
    bool stop;

    string getThreadId() {
        ostringstream ss;
        ss << this_thread::get_id();
        return ss.str();
    }

    void run() {
        while (true) {
            unique_lock<mutex> lock(taskMutex);
            cv.wait(lock, [this]() {
                return stop || this->tasks.size() > 0;
            });

            if (stop && tasks.size() == 0) {
                return;
            }

            Task* front = tasks.front(); tasks.pop();
            lock.unlock();

            printf ("Thread ID = '%s' working on Task '%s'\n", getThreadId().c_str(), front->getName().c_str());
            front->run();
            delete front;
        }
    }

public:
    ThreadPool(int _size): size(_size) {}
    ~ThreadPool() {
        cout << "ThreadPool Destructor Called, Thread ID = " << this_thread::get_id() << endl;

        stop = true;
        cv.notify_all();    // Signal Other Threads about the Stop
        
        // Join the Threads to MAIN thread
        for (auto &w: workers) {
            w.join();
        }
    }

    void addThread() {
        if (workers.size() < size) {
            workers.emplace_back(&ThreadPool::run, this);
            cout << "Worker Added, Thread ID = " << workers.back().get_id() << endl;
        } else {
            throw ThreadPoolWorkerException("Max Worker Limit Reached");
        }
    }

    void addTask(Task *task) {
        unique_lock<mutex> lock(taskMutex);
        printf ("Added Task with Name: '%s'\n", task->getName().c_str());
        tasks.push(task);
        lock.unlock();
        
        // Notify one thread to pick the task
        cv.notify_one();
    }
};


int main() {
    unique_ptr<ThreadPool> pool = make_unique<ThreadPool>(4);

    for (int i = 0; i < 6; i++) {
        try {
            pool->addThread();
        } catch (ThreadPoolWorkerException &e) {
            cout << e.what() << endl;
        }
    }

    int taskCount = 10;

    for (int i = 0; i < taskCount; i++) {
        pool->addTask(new Task(to_string(i)));
    }

    // auto now = chrono::system_clock::now();
    // auto duration = now.time_since_epoch();
    // auto milliseconds = chrono::duration_cast<chrono::milliseconds>(duration).count();
    // cout << milliseconds << endl;

    // time_t tt;
    // tt = chrono::system_clock::to_time_t(now);
    // cout << ctime(&tt) << endl;

    this_thread::sleep_for(chrono::seconds(10));

    return 0;
}