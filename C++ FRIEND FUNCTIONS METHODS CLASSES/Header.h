#pragma once

#include <iostream>
using namespace std;


class TestClass {
private:
    string cat_name = "CAT BARSIK";

    string cat_name2 = "CAT VASYA" ;

    static const int n = 10;

    static void my_static() {
        cout << "THIS IS STATIC METHOD CALLED BY FRIEND CLASS!" << endl;
    }

    // ��� ����� �������� ����������� ������
    inline static const string cat_name3 = "CAT PUSHOK";

    static const char* cat_name4;

    // ������������� �������
    friend void read_private_field(TestClass obj);

    // ������������� ����� (���������� ������� �������� ������������� �����)
    friend class Reader_private_field;
    friend void read_private(TestClass obj);

    // ������������� �����
    friend class Reader_friendly;
   
};

class Reader_private_field {
public:
    void read_private(TestClass obj);
};