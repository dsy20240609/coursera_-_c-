#include<iostream>
#include<iomanip>

using namespace std;
int main() {
    double value;
    cin>> value;
    std::cout<< std::fixed << std::setprecision(5) <<value << std::endl;
    std::cout<<std::scientific<<std::setprecision(7);
    std::cout<< value<<endl;
    return 0;
}
