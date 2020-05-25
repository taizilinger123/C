#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    string food = "Pizza";
    string &meal = food;
    string* ptr = &food;


    cout << food << "\n";   // Outputs Pizza
    cout << meal << "\n";   // Outputs Pizza
    cout << &meal << "\n";  //0x
    cout << &food << "\n";  //0x
    cout << ptr << "\n";    //0x
    cout << *ptr << "\n";   // Outputs Pizza
    return 0;
}
