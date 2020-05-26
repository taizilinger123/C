#include <iostream>
using namespace std;

// Base class
class Vehicle {
  public:
    string brand = "Ford";
    void honk() {
      cout << "Tuut, tuut! \n" ;
    }
};

// Derived class
class Car: public Vehicle {
  public:
    string model = "Mustang";
};

int main() {
  Car myCar;
  myCar.honk();  //Tuut, tuut!
  cout << myCar.brand + " " + myCar.model;//Ford Mustang
  return 0;
}
