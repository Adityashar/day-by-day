#include "common/common.h"

using namespace std;

int shared_variable = 0;

/**
 * Simple Function to replicate two threads
 * T1 and T2
 */
void addToVariable1(string thread_name, int value, int iterations) {
    for (int i = 0; i < iterations; i++) {
        shared_variable += value;
        printf("shared_variable = %d, change by thread = %s\n", shared_variable, thread_name.c_str());
    }
}

void example1 () {
    thread t1(addToVariable1, "T1", 1, 35);
    thread t2(addToVariable1, "T2", -5, 20);
    t1.join();
    t2.join();
}

mutex m;

void addToVariable2(string thread_name, int value, int iterations) {
    for (int i = 0; i < iterations; i++) {
        
        // Block threads until mutex is available
        m.lock();
        shared_variable += value;
        printf("shared_variable = %d, change by thread = %s\n", shared_variable, thread_name.c_str());
        m.unlock();
    }
}

void example2 () {
    thread t1(addToVariable2, "T1", 1, 35);
    thread t2(addToVariable2, "T2", -5, 20);
    t1.join();
    t2.join();
}

/**
 * A Timed Mutex
 * Wait for X seconds till the mutex is available
 * Else MOVE ON
 */

timed_mutex m2;

void addToVariable3(string thread_name, int value, int iterations) {
    for (int i = 0; i < iterations; i++) {
        // Block threads for 1s until mutex is available
        if (m2.try_lock_for(chrono::milliseconds(1500))) {
            shared_variable += value;
            printf("shared_variable = %d, change by thread = %s\n", shared_variable, thread_name.c_str());
            m2.unlock();

            this_thread::sleep_for(chrono::seconds(1));
        } else {
            cout << "Failed to get lock, thread = " << thread_name.c_str() << endl;
        }
    }
}

void addToVariable4(string thread_name, int value, int iterations) {
    for (int i = 0; i < iterations; i++) {
        // Block threads for 1s until a specific time
        auto until = chrono::steady_clock::now() + chrono::milliseconds(200);
        if (m2.try_lock_until(until)) {
            shared_variable += value;
            printf("shared_variable = %d, change by thread = %s\n", shared_variable, thread_name.c_str());

            this_thread::sleep_for(chrono::seconds(10));
            m2.unlock();
        } else {
            cout << "Failed to get lock, thread = " << thread_name.c_str() << endl;
        }
    }
}


int main() {
    thread t1(addToVariable4, "T1", 1, 1);
    thread t2(addToVariable4, "T2", -1, 1);
    t1.join();
    t2.join();

    cout << "Final Value: " << shared_variable << endl;
}

// g++ -std=c++17 -pthread -o ~/dump/builds/build example1.cpp; ~/dump/builds/build