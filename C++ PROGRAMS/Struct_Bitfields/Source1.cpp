#include <vector>
#include <iostream>


struct bitfield4 { unsigned ready : 1, active : 1, c : 2, d : 4; } dev_code;

std::vector <bitfield4> Vector_of_Stucture;


 



int main() {

	dev_code.ready = 1;
	dev_code.active = 0;
	dev_code.c = 39;        // ќбрезает число, оставл€€ первую цифру
	dev_code.d = 9;

	Vector_of_Structure [1] = 7;
	Vector_of_Structure.b[1] = -7;
	Vector_of_Structure.c[1] = 10;
	Vector_of_Structure.d[1] = 100;

std::cout << dev_code.d << std::endl;

return 0;
}
