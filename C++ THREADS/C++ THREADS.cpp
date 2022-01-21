
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>

using namespace std;


int main()
{
    auto task = [](int n, mutex& my_mutex1, mutex& my_mutex2) {
       
        my_mutex1.lock();
        cout << " Thread " << this_thread::get_id() << " is running" << endl;
        my_mutex1.unlock();
        for (int i = 0; i < n; i++) {
            this_thread::sleep_for(chrono::seconds(1));
        }
        my_mutex2.lock();
        cout << " Thread " << this_thread::get_id() << " finished" << endl;
        my_mutex2.unlock();
    };
      
    vector<thread> thread_pool;
    mutex my_mutex1;
    mutex my_mutex2;
    
    for (int i = 0; i < 5; i++) {
        thread current_thread(task, 5, ref(my_mutex1), ref(my_mutex2));
        thread_pool.push_back(move(current_thread));
    }

    for (thread& t : thread_pool) {
        t.detach();
    }

    

    this_thread::sleep_for(chrono::seconds(10));
}