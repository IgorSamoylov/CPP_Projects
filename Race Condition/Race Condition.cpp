
#include <iostream>
#include <thread>

using namespace std;

auto incrementer = [](bool& stop, int& n) {
    while(!stop) {
        n++;
    }
};

auto odd_check = [](bool& stop, int& n) {
    while (!stop) {
        int ln = n;
        // инкремент успевает увеличить значение на 1, что может привести к выдаче нечётных чисел?
        if (ln % 2 == 0) cout << ln << endl; 
    }
};

int main() {
    bool stop = false;
    int n = 0;

    thread thread1(incrementer, ref(stop), ref(n)); thread1.detach();
    thread thread2(odd_check, ref(stop), ref(n)); thread2.detach();

    this_thread::sleep_for(chrono::milliseconds(200));

    stop = true;
   
}

