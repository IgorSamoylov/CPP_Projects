

#include <iostream>
using namespace std;


class Person {
    string name = "Fransua", surname = "Sholle";
public:
    Person(string name, string surname) : name(name), surname(surname) {}

    void set_name(string name) { this->name = move(name); }

    void set_surname(string surname) { this->surname = move(surname); }

    const string& get_name() const& { return this->name; }

    const string& get_surname() const& { return surname; }

    const string get_name()  && { return move(name); } // << Переменная auto& получает из этого

    const string get_surname()  && { return move(surname); } // << В цикле for итерирует по этому геттеру

    void operator -- () {}
};

Person make() {   // << Данная функция возвращает объект класса Person!
    return Person("John", "Smith");
}
/*
Person make() {   // << Данная функция возвращает объект класса Person!
    return {};
}*/

int main()
{
    auto& x = make().get_name();

    std::cout << x << std::endl;

    for (auto letter : make().get_surname()) {
        std::cout << letter << ",";
    }
    
   /* Person person1;
    person1.set_name("Antoiane");
    person1.set_surname("Sholle");


    cout << person1.get_name() << " " << person1.get_surname() << endl;*/
}

