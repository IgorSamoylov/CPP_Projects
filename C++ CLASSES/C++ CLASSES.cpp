#include <iostream>
using namespace std;

class TestClass {

public:
	int x = 1000;

	TestClass() {
		cout << "Object is created! " << endl; //Конструктор
	}

	~TestClass() {
		cout << "Object has been destroyed! " << endl; //Так выглядит деструктор, выполняемый при удалении объекта
	}
};

void main(int n, char *args) {

	TestClass* testClass = new TestClass(); //new создаёт объект в куче и возвращает только указатель!

	cout << (*testClass).x << endl; 
	// так получаем доступ к полю, а разадресация указателя на объект выполняется первой, для этого нужны скобки

	delete(testClass); // не забыть удалить, сборщика мусора нет!
	

	TestClass testClass2; //такая запись создаёт объект в стеке и его временем жизни C++ управляет автоматически
	cout << testClass2.x << endl; //обращение к полю идёт уже через ссылку, не через указатель как с new

}