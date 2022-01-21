
#include "Header.h"
#include <cassert> // для assert()



int main()
{
    constexpr auto name = "VASIA";

    TestClass* testClass = new TestClass(name);
    std::cout << testClass->name << std::endl;
    delete testClass;

    // Так создаётся умный указатель на объект
    std::unique_ptr<TestClass> obj1(new TestClass("BARSIK"));
    std::cout << obj1->name << std::endl;
    
    // Так нельзя, потому что указатель - уникальный
    //auto obj2 = obj1;

    //А так передаём право "владения" уникальным указателем
    std::unique_ptr<TestClass> obj2 = std::move(obj1);
    obj2->create_array();

    //shared_ptr позволяет "делиться" ссылками, но имеет проблему с "зациклением" ссылок
    std::shared_ptr<TestClass> obj3ptr(new TestClass("SNEJOK"));
    /*Создаем ещё один указатель на объект, для shared_ptr это приветствуется (имеет счётчик ссылок внутри,
    автоматически удаляющий объект при достижении 0 */
    auto obj4ptr = obj3ptr;
    assert(obj3ptr == obj4ptr);
    obj4ptr->name;

    /*Слабый указатель, предотвращает возникновение "циклических" ссылок,
    поскольку не участвует в подсчете ссылок */

    auto ptr = std::make_shared<TestClass>("PUSHOK");
    std::weak_ptr<TestClass> obj5ptr = ptr;
    //Слабый указатель имеет метод lock(), позволяющий временно вернуть shared_ptr 
    auto tmpPtr = obj5ptr.lock(); 
    std::cout << tmpPtr->name << std::endl;

    
}


//Конструктор класса, объявленного в Header.h
TestClass::TestClass(std::string name) {
        name.append(" is good!");
        this->name = name;
 }

void TestClass::create_array() {
    // Так создаётся динамический массив. Обратите внимание на указатель - просто int*
    int* array = new int[100];
  
    for (int i{}; i < 100; ++i) {
        array[i] = i;
    }

    int* array2 = new int[100];

    //Так можно наиболее быстро скопировать массив и вообще любой объект - функция memcpy
    memcpy(array2, array, 100);

    std::cout << *(array + 10) << " " << array2[10] << std::endl;

    //Пробуем метод C для выделения памяти и копируем в неё текущий объект
    TestClass* mallocClass = (TestClass*) malloc(sizeof(*this));
    /* Указатель на TestClass имя = (Приведение типа void*, возвращаемого malloc к указателю на TestClass,
    затем выделение памяти функцией malloc, куда передаётся РАЗЫМЕНОВАННЫЙ указатель на текущий инстанс
    объекта (если передать просто this - то вычислится размер указателя this, а не объекта)
    */
    if (!mallocClass) { std::cout << "Allocation failure!"; exit(1); }
    else {
        memcpy(mallocClass, this, sizeof(*this));

        std::cout << mallocClass->name << " Using malloc function for this" << std::endl;

        //Так освобождаем память после malloc
        free(mallocClass);
    }
}


