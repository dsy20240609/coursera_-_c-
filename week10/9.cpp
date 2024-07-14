#include<set>
#include<algorithm>
#include<iostream>
using namespace std;
class A {
public:
    int val;
    int type;
    A(int k) : val(k) {
        type = 0;
    }
    int getVal()  {return val;}
    int getType() {return type;}
};

class B : public A {
public:
    B(int k) : A(k) {
        type =1;   
    }
};

//struct Print{
//    void operator() (A &a) {
//        if(a.getType() == 0) {
//	    cout<< "A " << a.getVal() << endl;
//	} else {
//	    cout<< "B " << a.getVal() << endl;
//	}
//    }
//}; if I wrote the Print as struct and it needs to be called by Print()
void Print(A* a) {
  if(a->getType() == 0) {
      cout<< "A " << a->getVal() << endl;
  } else {
      cout<< "B " << a->getVal() << endl;
  }
}



struct Comp {
    bool operator()(A * a, A* b) const {
        return a->getVal() < b->getVal();
    }
};



int main()
{

        int t;
        cin >> t;
        set<A*,Comp> ct;
        while( t -- ) {
                int n;
                cin >> n;
                ct.clear();
                for( int i = 0;i < n; ++i)	{
                        char c; int k;
                        cin >> c >> k;

                        if( c == 'A')
                                ct.insert(new A(k));
                        else
                                ct.insert(new B(k));
                }
                for_each(ct.begin(),ct.end(),Print);
                cout << "****" << endl;
        }
}

//在 C++ 中，你可以使用自定义比较器来传递给 std::set 的构造函数，以实现特定的排序规则。自定义比较器可以是函数对象、函数指针或 lambda 表达式。
//
//使用函数对象作为比较器
//以下是一个示例，展示了如何定义和使用函数对象作为比较器：
//
//#include <iostream>
//#include <set>
//
//// 自定义比较器
//struct MyComparator {
//    bool operator()(int a, int b) const {
//        return a > b; // 降序排列
//    }
//};
//
//int main() {
//    std::set<int, MyComparator> mySet = {5, 1, 4, 2, 3};
//
//    for (int elem : mySet) {
//        std::cout << elem << " ";
//    }
//
//    return 0;
//}
//
//使用函数指针作为比较器
//你还可以使用函数指针来实现自定义比较器：
//
//#include <iostream>
//#include <set>
//
//// 比较函数
//bool myComparator(int a, int b) {
//    return a > b; // 降序排列
//}
//
//int main() {
//    std::set<int, decltype(&myComparator)> mySet(&myComparator);
//
//    mySet.insert(5);
//    mySet.insert(1);
//    mySet.insert(4);
//    mySet.insert(2);
//    mySet.insert(3);
//
//    for (int elem : mySet) {
//        std::cout << elem << " ";
//    }
//
//    return 0;
//}
//使用 lambda 表达式作为比较器
//lambda 表达式也可以用作比较器：
//
//#include <iostream>
//#include <set>
//
//int main() {
//    auto myComparator = [](int a, int b) { return a > b; }; // 降序排列
//
//    std::set<int, decltype(myComparator)> mySet(myComparator);
//
//    mySet.insert(5);
//    mySet.insert(1);
//    mySet.insert(4);
//    mySet.insert(2);
//    mySet.insert(3);
//
//    for (int elem : mySet) {
//        std::cout << elem << " ";
//    }
//
//    return 0;
//}
//使用带有自定义类型的比较器
//如果你的集合包含的是自定义类型，你也可以定义一个比较器：
//
//#include <iostream>
//#include <set>
//
//struct MyType {
//    int value;
//};
//
//// 自定义比较器
//struct MyComparator {
//    bool operator()(const MyType& a, const MyType& b) const {
//        return a.value < b.value; // 升序排列
//    }
//};
//
//int main() {
//    std::set<MyType, MyComparator> mySet = {{5}, {1}, {4}, {2}, {3}};
//
//    for (const auto& elem : mySet) {
//        std::cout << elem.value << " ";
//    }
//
//    return 0;
//}
//通过这些示例，你可以看到如何定义和使用自定义比较器，以便在创建 std::set 对象时传递给构造函数，从而实现特定的排序规则。根据你的需求选择合适的方法。
