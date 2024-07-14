#include <iostream>
using namespace std;
class A {
public:
    int val;
    A() {val=0;}
    int& GetObj() {return this->val;}
// 在此处补充你的代码
};
main()  {
    A a;
    cout << a.val << endl;
    a.GetObj() = 5;
    cout << a.val << endl;
}
