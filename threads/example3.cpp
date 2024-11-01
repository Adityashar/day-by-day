#include "common/common.h"
using namespace std;

class Notify {
    mutex m;
    condition_variable cv;
    int shared_variable;
public:
    Notify(): shared_variable(0) {}

    void produce(int val, string threadName) {
        unique_lock<mutex> lock(m);

        printf("Waiting, producer_thread_name = %s\n", threadName.c_str());
        cv.wait(lock, [this]() {
            return this->shared_variable == 0;
        });

        printf("Producing, producer_thread_name = %s\n", threadName.c_str());

        shared_variable += val;
        printf("shared_variable = %d, producer_thread_name = %s\n", shared_variable, threadName.c_str());
        cv.notify_all();
    }

    void consume(string threadName) {
        unique_lock<mutex> lock(m);

        printf("Waiting, consumer_thread_name = %s\n", threadName.c_str());
        cv.wait(lock, [this]() {
            return this->shared_variable > 0;
        });
        
        printf("Consuming, consumer_thread_name = %s\n", threadName.c_str());

        shared_variable -= 1;

        this_thread::sleep_for(chrono::seconds(1));

        printf("shared_variable = %d, consumer_thread_name = %s\n", shared_variable, threadName.c_str());
        cv.notify_all();
    }
};

void daemonTask() {
    while (true) {
        cout << "Daemon Working \n";
        this_thread::sleep_for(chrono::seconds(1)); 
    }
}

int main() {
    Notify *notify = new Notify();

    vector<thread> threadsList;
    vector<thread::id> threadIds;


    /**
     * Daemon Thread, Run in background to perform some non-impacting chores or cleanup tasks
     */
    thread daemon(daemonTask);
    daemon.detach();

    for (int i = 0; i < 2; i++) {
        thread t(&Notify::produce, notify, 4, to_string(i));
        /**
         * Threads can't be copied so use move
         */
        threadsList.push_back(move(t));
        threadIds.push_back(t.get_id());

        cout << "Created Producer with ID: " << t.get_id() << endl;
    }

    for (int i = 2; i < 8; i++) {
        thread t(&Notify::consume, notify, to_string(i));
        threadsList.push_back(move(t));
        threadIds.push_back(t.get_id());

        cout << "Created Consumer with ID: " << t.get_id() << endl;
    }


    for (int i = 0; i < 8; i++) {
        threadsList[i].join();
    }

    delete notify;
}


