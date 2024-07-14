#include <iostream>
using namespace std;
// 在此处补充你的代码
template <class T>
class CArray3D 
{
    template <class T1>
    class CArray2D {
      private:
      T** data;
      int row;
      int column;
      public:
      CArray2D<T1>(): data(nullptr),row(0),column(0) {}
      CArray2D<T1>(int r, int c) {
          data =new T*[r];
	  for(int i = 0 ; i < r; ++i) {
	      data[i]=new T[c];
	  }
          row=r;
          column=c;
      }

      T1* operator[](int i) {
          if(i < 0 || i > row ) {
	      std::cout<< "Row index out of bounds" << std::endl;
	  }
	  return data[i];
      }
      //~CArray2D<T1> {
      //    for(int i = 0 ; i < row; i++) {
      //        delete [] data[i];
      //    }
      //    delete data;
      //}
    };


    private:
    CArray2D<T> * data;
    int x;
    int y;
    int z;

    public:
    CArray3D<T>(): data(nullptr),x(0),y(0),z(0) {}
    CArray3D<T>(int a, int b, int c) {
        data=new CArray2D<T>[a];
        for(int i = 0 ; i <a ; i ++) {
	    data[i] = *new CArray2D<T>(b,c);
	}	
        x=a;
        y=b;
        z=c;
    }
    CArray2D<T> operator[](int i) {
        if(i < 0 || i > x) {
	    std::cout << "Row index out of bounds" << std::endl;
	}
	return data[i];
    }

};

int main()
{
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";
    return 0;
}
