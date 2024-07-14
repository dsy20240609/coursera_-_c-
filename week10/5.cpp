#include<iostream>
#include<cmath>
#include <vector>
#include <algorithm>
using namespace std;
// 在此处补充你的代码

//void CMy_add(int i, int& sum) {
//    int tmp =(int) sqrt(i);
//    int remain= i - pow(2,tmp) ;
//    sum=sum+remain;
//}

struct CMy_add{
    int &sum;
    CMy_add(int& s) : sum(s){};
    void operator()(int n) {
	if(n < 8) {
	    sum+=n;
	} else {
            int tmp = (int) log2(n);
	    int remain = n - pow(2,tmp);
            sum=sum+remain;
	}
    }
};


int main(int argc, char* argv[]) {
        int v, my_sum=0;
        vector<int> vec;
        cin>>v;
        while ( v ) {
                vec.push_back(v);
                cin>>v;
        }
        for_each(vec.begin(), vec.end(), CMy_add(my_sum));
        cout<<my_sum<<endl;
        return 0;
}


//std::for_each example
//// for_each example
//#include <iostream>     // std::cout
//#include <algorithm>    // std::for_each
//#include <vector>       // std::vector
//
//void myfunction (int i) {  // function:
//  std::cout << ' ' << i;
//}
//
//struct myclass {           // function object type:
//  void operator() (int i) {std::cout << ' ' << i;}
//} myobject;
//
//int main () {
//  std::vector<int> myvector;
//  myvector.push_back(10);
//  myvector.push_back(20);
//  myvector.push_back(30);
//
//  std::cout << "myvector contains:";
//  for_each (myvector.begin(), myvector.end(), myfunction);
//  std::cout << '\n';
//
//  // or:
//  std::cout << "myvector contains:";
//  for_each (myvector.begin(), myvector.end(), myobject);
//  std::cout << '\n';
//
//  return 0;
//}
