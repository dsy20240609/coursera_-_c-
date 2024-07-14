#include <iostream>
using namespace std;
// 在此处补充你的代码
class CType {
    public:
	    int val;
    public:
     CType() {};
     int operator++(int n) {
         int temp = val;
	 val=val*val;
	 return temp; //need some tricks
     }
     void setvalue(int n) {
         val=n;
     }
     friend std::ostream & operator<<(std::ostream& o, const CType &s);
};

ostream & operator<<(ostream &o,const CType &s) {
    o<<s.val;
    return o;
}

int main(int argc, char* argv[]) {
        CType obj;
        int n;
        cin>>n;
        while ( n ) {
                obj.setvalue(n);
                cout<<obj++<<" "<<obj<<endl;
                cin>>n;
        }
        return 0;
}
