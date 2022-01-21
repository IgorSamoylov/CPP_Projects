#include <iostream>
#include <thread>
#include <future>
#include <chrono>

using namespace std;

int main() {

   auto myTask = [](int n) {
        cout << "Task is running! Recieving parameter: " << n << endl;
        this_thread::sleep_for(chrono::seconds(5));
        
        long pow = n * n;
        string res = "Task complete! " + to_string(pow);
        return res;
    };

    packaged_task<string (int)> m_task(myTask); // В шаблоне packaged_task <возвращаемое значение (входные аргументы)>

    future<string> myFuture = m_task.get_future(); // Перед отсоединением потока заказываем future из packaged_task методом get_future()

    // Запуск потока. Передача права владения packaged_task в констуктор потока через move
    thread thread_for_task (move(m_task), 777); 

    thread_for_task.detach();
    
    cout << myFuture.get() << endl; // Блокирующий метод future.get(), останавливает выполнение main до получения приемлемого результата

    

    // Работа с packeged_task 

    // Создаем объект pachaged_task с нужными типами, передаём в конструктор лямбду для асинхронного выполнения 
    packaged_task<int(int, int)> task([](int a, int b) { return a + b; });

    future<int> future1 = task.get_future(); // packaged_task умеет давать future

/* Здесь запускаем packaged_task с параметрами, 
    передавая право владения packeged_task создаваемому потоку посредством move */
    thread task_thread(move(task), 1000, 1); 

    cout << future1.get() << endl; // Блокируем main до получения future методом get 

    task_thread.join();


    // Работа с promise

    promise<int> my_promise; // Создаём promise шаблонного типа из "воздуха"
    future<int> my_future = my_promise.get_future(); // Сразу же получаем у него future шаблонного типа

    auto promise_lambda = [&](int n) { // В лямбду promise передаём по ссылке, или move для функции
        this_thread::sleep_for(chrono::seconds(5));
        my_promise.set_value(n * 2); // Здесь устанавливаем значение promise, сама функция возвращает void
    };

    thread thread_for_promise(promise_lambda, 100); // Создаем поток и запускаем в нем лямбду с параметром

    cout << my_future.get() << endl; // Здесь исполнение main блокируется до получения future
    
    thread_for_promise.join(); // Присоединяем созданный поток к main для его завершения
}

