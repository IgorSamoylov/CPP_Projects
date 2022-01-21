
#include <iostream>
#include <string>
#include <cstdlib>
#include <Windows.h>
#include <clocale>

using namespace std;





string KoT (string &argument )  {

    string Result;

    string V = "kis-kis";
    if (argument == V) Result = "Mjav-Mjav";

    return Result;
}






int main()
{


    int N;

    string V = "kis-kis";

    cout << KoT (V)<< endl;
    cin >>N;
    return 0;
}
