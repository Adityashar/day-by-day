#include <chrono>
#include <iostream>
#include <thread>

using namespace std;


int main() {
    auto now = chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto milliseconds = chrono::duration_cast<chrono::milliseconds>(duration).count();
    
    cout << milliseconds << endl;

    time_t tt;
    tt = chrono::system_clock::to_time_t(now);
    cout << ctime(&tt) << endl;

    this_thread::sleep_for(chrono::seconds(2));
}