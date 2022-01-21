

#include <iostream>

class BitOperation {

    unsigned int A = 64;
    unsigned int B = 65;


    public:
    unsigned int NE() {
    return ~this->A;
    }


    unsigned int I() {
        return (this->A & this->B);
    }


    unsigned int ILI() {
        return (this->A | this->B);
    }


    unsigned int XOR() {
        return (this->A ^ this->B);
    }


};


int main()
{
    unsigned int x = 4;// Использовать только unsigned при работе с побитовыми операциями

    x = x << 1; //Сдвиг 4 (0100) на 1 бит влево (1000),т.е. получается 8 

    std::cout << x << std::endl;

    BitOperation object;
    
    std::cout << object.NE() << " " << object.I() << " " << object.ILI() << " " << object.XOR();
}