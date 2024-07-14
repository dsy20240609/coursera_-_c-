#include<iostream>
#include<iterator>
#include<set>

using namespace std;

struct CustomCompare {
    bool operator()(const int &lhs, const int &rhs) const {
        return lhs < rhs;
    }
};

int main() {
    int a[] = {8,7,8,9,6,2,1};
    std::set<int,CustomCompare> v(a,a+7);
    ostream_iterator<int> o(cout, " ");
    copy(v.begin(), v.end(),o);
    return 0;
}

//reference code from chatgpt and set constructor
//#include <iostream>
//#include <set>
//
//struct CustomCompare {
//    bool operator()(const int& lhs, const int& rhs) const {
//        return lhs > rhs;  // 降序排序
//    }
//};
//
//int main() {
//    std::set<int, CustomCompare> s = {4, 2, 5, 3, 1};
//
//    for (int n : s) {
//        std::cout << n << ' ';
//    }
//    std::cout << std::endl;
//
//    return 0;
//}

// constructing sets
//#include <iostream>
//#include <set>
//
//bool fncomp (int lhs, int rhs) {return lhs<rhs;}
//
//struct classcomp {
//  bool operator() (const int& lhs, const int& rhs) const
//  {return lhs<rhs;}
//};
//
//int main ()
//{
//  std::set<int> first;                           // empty set of ints
//
//  int myints[]= {10,20,30,40,50};
//  std::set<int> second (myints,myints+5);        // range
//
//  std::set<int> third (second);                  // a copy of second
//
//  std::set<int> fourth (second.begin(), second.end());  // iterator ctor.
//
//  std::set<int,classcomp> fifth;                 // class as Compare
//
//  bool(*fn_pt)(int,int) = fncomp;
//  std::set<int,bool(*)(int,int)> sixth (fn_pt);  // function pointer as Compare
//
//  return 0;
//}
