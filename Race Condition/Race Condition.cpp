
#include <iostream>
#include <thread>
#include <barrier>
using namespace std;

bool stop = false;
volatile int n = 0;

auto incrementer = []() noexcept {
    while(!stop) {
        n++;
    }
};

auto odd_check = []() noexcept {
    while (!stop) {
        int ln = n;
        // инкремент успевает увеличить значение на 1, что приводит к выдаче нечётных чисел!
        if (ln % 2 == 0) cout << ln << endl; 
    }
};

int main() {
    thread thread1(incrementer); thread1.detach();
    thread thread2(odd_check); thread2.detach();

    this_thread::sleep_for(chrono::milliseconds(100));

    stop = true;
   
}

