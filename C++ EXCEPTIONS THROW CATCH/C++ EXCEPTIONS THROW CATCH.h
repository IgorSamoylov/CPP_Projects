#pragma once

#include <iostream>
using namespace std;

class MyException {
public:  // Конструктор должен быть явно объявлен как public, иначе будет private по умолчанию
	MyException(string message);
};
