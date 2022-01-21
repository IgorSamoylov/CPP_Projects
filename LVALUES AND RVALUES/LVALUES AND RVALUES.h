#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

class A {

public:
	std::vector<int> myVector;
	A(std::vector<int> inputVector) {
		myVector = inputVector;
		std::cout << "Object A is created!" << std::endl;
	}
	int getFirstElem() {
		return myVector[0];
	}

	void swaper(std::vector<int>& vector1, std::vector<int>& vector2) {
		// std::move преобразует неконстантную lvalue-ссылку в rvalue-ссылку
		std::vector<int>&& TempRValueReference = std::move(vector1);
		vector1 = std::move(vector2);
		vector2 = TempRValueReference;
		
	}

	template <typename T>
	void universalSwaper(T& item1, T& item2) {
		T TempReference(std::move(item1));
		item1 = std::move(item2);
		item2 = TempReference;
		
	}
};

struct CustomCompare {
	 bool operator () (const int& item1, const int& item2) const {
		return item2 < item1;
	}
};