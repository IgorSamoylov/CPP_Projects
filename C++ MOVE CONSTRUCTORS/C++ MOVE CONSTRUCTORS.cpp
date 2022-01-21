#include <iostream>

template <typename T>
class TestClass {
    T* object_ptr;

public: 
    TestClass(T* input_ptr = nullptr) : object_ptr(input_ptr) {}

    ~TestClass() { delete object_ptr; }

    // Copy constructor for deep copy
    TestClass(const TestClass& basic_object) {
        object_ptr = new T;
        *object_ptr = *basic_object.object_ptr;
    }

    // Move constructor

	// Конструктор перемещения, который передает право собственности на x.object_ptr в object_ptr
	TestClass(TestClass&& x) : object_ptr(x.object_ptr) 
	{
		x.object_ptr = nullptr; // мы поговорим об этом чуть позже
	}

	// Оператор присваивания копированием, который выполняет глубокое копирование x.object_ptr в object_ptr
	TestClass& operator=(const TestClass& x)
	{
		// Проверка на самоприсваивание
		if (&x == this)
			return *this;

		// Удаляем всё, что к этому моменту может хранить указатель 
		delete object_ptr;

		// Копируем передаваемый объект
		object_ptr = new T;
		*object_ptr = *x.object_ptr;

		return *this;
	}

	// Оператор присваивания перемещением, который передает право собственности на x.m_ptr в m_ptr
	TestClass& operator=(TestClass&& x)
	{
		// Проверка на самоприсваивание
		if (&x == this)
			return *this;

		// Удаляем всё, что к этому моменту может хранить указатель 
		delete object_ptr;

		// Передаем право собственности на x.m_ptr в m_ptr
		object_ptr = x.object_ptr;
		x.object_ptr = nullptr; // мы поговорим об этом чуть позже

		return *this;
	}

	T& operator*() const { return *object_ptr; }
	T* operator->() const { return object_ptr; }
	bool isNull() const { return object_ptr == nullptr; }
};




class Item
{
public:
    Item() { std::cout << "Item acquired\n"; }
    ~Item() { std::cout << "Item destroyed\n"; }
};

TestClass<Item> generateItem() {
    TestClass<Item> item(new Item);
    return item; // это возвращаемое значение приведет к вызову конструктора перемещения
}

int main() {
    TestClass<Item> mainItem;
    mainItem = generateItem(); // эта операция присваивания приведет к вызову оператора присваивания перемещением


}