#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
    Complex& operator=(char* s) {
        if(s) {
            char ch='+';
            char in= 'i';
            char * locPlus=strchr(s,ch);
            char * locI= strchr(s,in);
            if(locPlus) {
               char  real[locPlus-s+1];
               std::strncpy(real,s,locPlus-s);
               real[locPlus-s]='\0';
printf("line 22 %s\n",real);
               r=std::stod(real);
printf("line 24 %f\n",r);
            }
            if(locI) {
               char  image[locI-locPlus];
               std::strncpy(image,locPlus+1,(locI-locPlus)-1);
               image[locI-locPlus]='\0';
printf("line 29 %s\n",image);
               i=std::stod(image);
printf("line 32 %f\n",i);
            }
        } 
    }
// 在此处补充你的代码
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
