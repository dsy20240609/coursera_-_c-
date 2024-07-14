#include<iostream>
#include<iomanip>

using namespace std;
int main () {
  int value;
  cin>> value;
  std::cout<< std::hex << value<< std::endl;
  std::cout<< std::setw(10) << std::setfill('0') << value << std::endl;
  return 0;
}
