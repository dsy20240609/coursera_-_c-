#include<iostream>
using namespace std;
class CStudent{
  public: int nAge;
  friend std::ostream & operator<<(std::ostream& o,const CStudent & s);	  
  };

ostream & operator<<(ostream &o, const CStudent &s) {
      o<<s.nAge;
      return o;
}

int main () {
    CStudent s;
    s.nAge=5;
    cout<<s<<"hello";
    return 0;
}
