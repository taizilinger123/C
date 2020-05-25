#include <iostream>
using namespace std;

void myFunction(string fname) {
  cout << fname << " Refsnes\n";
}

int main() {
  myFunction("Liam");//Liam  Refsnes
  myFunction("Jenny");
  myFunction("Anja");
  return 0;
}
