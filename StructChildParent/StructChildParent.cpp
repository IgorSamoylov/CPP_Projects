// StructChildParent.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class Child
{
	std::string getName() const;
	std::string& getName();
};

class Parent
{
	Child getChild() const; 
};




void doSmth(const Parent& p)
{
	const auto& name = p.getChild().getName();
	std::cout << &name << std::endl;
	//std::cout << static_cast <std::string> (p.getChild().getName());
	// дальше работаем с name
}

int main(int argc, char *argv[]) {

	Parent ParentObject;
	doSmth(ParentObject);

}

std::string Child::getName() const
{
	
	return "YOU ARE PETUX!";
}

std::string& Child::getName()
{
	std::string Name = "PIDORAS";
	return Name;
}

Child Parent::getChild() const
{
	
	return Child();
}
