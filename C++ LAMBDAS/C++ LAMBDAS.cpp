
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void fillVector(std::vector<int>& v) {
	static int it = 0;
	// generate применяет к каждому элементу между итератором1 и итератором2  переданную функцию
	std::generate(v.begin(), v.end(), [] {return it++; });
}



int main() {
	//ПРОСТАЯ ЛЯМБДА
	auto lambda1 = [](int n) {
		return n * n;
	};
	std::cout << lambda1(5) << std::endl;


	std::vector<int> myVector;

	//Изменять длину вектора следует функцией resize
	myVector.resize(25);

	fillVector(myVector);
	
	// [] - предложение фиксации. Захват внешней переменной по &ссылке или по значению.
	std::string numberStr = "Number: ";
	
	auto printVector = [&](int n) mutable noexcept {
		std::cout << numberStr << n << std::endl;
		return 0;
	};

	std::for_each(myVector.begin(), myVector.end(), printVector);



}
