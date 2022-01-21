

#include <iostream>
#include <thread>
#include <barrier>

using namespace std;

int n = 0, k = 0;
bool stop = false;
barrier my_barrier(2);

auto incrementer1 = []() noexcept {
    while (!stop) {
        for (int i = 0; i < 1000; i++) {
            n += i;
            my_barrier.arraive_and_wait();
        }
        cout << "Incrementer 1 " << this_thread::get_id() << " " << n << endl;
    }
};

auto incrementer2 = []() noexcept {
    while (!stop) {
        for (int i = 0; i < 2000; i++) {
            k += i;
            my_barrier.arraive_and_wait();
        }
        cout << "Incrementer 2 " << this_thread::get_id() << " " << k << endl;
    }
};

int main() {
    
    thread thread1(incrementer1); thread1.detach();
    thread thread2(incrementer2); thread2.detach();

    this_thread::sleep_for(chrono::milliseconds(100));

    stop = true;
}

