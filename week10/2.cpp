#include <iostream>
using namespace std;
class Number {
public:
    int num;
    Number(int n): num(n) {}
    Number& operator=(Number &a) {
        return *(new Number(a.num));
    }
    int & value() {return num;}
    const int & value() const {return num;}
    void operator+(Number & b) {
	    this->num=this->num+b.num;
    }
// 在此处补充你的代码
};
int main() {
    Number a(2);
    Number b = a;
    cout << a.value() << endl;
    cout << b.value() << endl;
    a.value() = 8;
    cout << a.value() << endl;
    a+b;
    cout << a.value() << endl;
    return 0;
}
