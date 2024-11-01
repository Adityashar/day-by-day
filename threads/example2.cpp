#include "common/common.h"
using namespace std;

int x = 0, y = 0;
mutex m1, m2;

/**
 * lock_guard and unique_lock
 * Exception handling while threading -> Safely release lock on failures or exceptions
 * Uses different locking strategies - 
 * - defer_lock: Create locks first, then acquire them with lock(m1, m2)
 * - adopt_lock: Acquire locks first, then wrap them with guards for safe release
 */
void task1 (string threadName, int _x, int _y) {
    unique_lock<mutex> lock1(m1, defer_lock);
    unique_lock<mutex> lock2(m2, defer_lock);

    if (try_lock(lock1, lock2) != -1) {
        cout << "Can't Acquire Mutex, thread = " << threadName << endl;
        return;
    }

    x += _x, y += _y;
    printf("X = %d, Y = %d, Thread Name = %s\n", x, y, threadName.c_str());
    this_thread::sleep_for(chrono::milliseconds(5000));
}


void task2(string threadName, int _x) {
    lock_guard<mutex> lock(m1);
    x += _x;
    printf("X = %d, Y = %d, Thread Name = %s\n", x, y, threadName.c_str());
    this_thread::sleep_for(chrono::milliseconds(5000));    
}


int main() {
    thread t1(task1, "T1", 1, 2);
    thread t2(task1, "T2", -2, -1);
    thread t3(task2, "T3", 10);

    t1.join(); t2.join(); t3.join();

    printf("x = %d, y = %d\n", x, y);
}