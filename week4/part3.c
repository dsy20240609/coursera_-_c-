#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码
class Array2 {
    public:
      int** data;
      int rows,cols;
      
    public:
    Array2():data(nullptr),rows(0),cols(0) {};
  //constructor
    Array2(int r ,int c): rows(r), cols(c) {
        data = new int*[rows];
	for(int i = 0 ; i < rows;++i) {
	    data[i]=new int[cols];
	}
    }
  //desctrucor
    ~Array2() {
        for(int i = 0 ; i < rows; ++i) {
	    delete[] data[i];
	}
	delete[] data;
    }
    //subscript operator for row access
    int* operator[](int row) {
        if(row < 0 || row >= rows) {
	    std::cout << "Row index out of bounds!" << std::endl;
	}
	return data[row];
    }
    // const version of subscript operator for row access
    const int* operator[](int row) const {
        if(row < 0 || row >= rows) {
	    std::cout << "Row index out of bounds1" <<std::endl;
	}
	return data[row];
    }

    //subscript operator for row access
    int operator() (int row,int col) {
        if(row < 0 || row >= rows) {
	    std::cout << "Row index out of bounds!" << std::endl;
	}
	if(col <0 || col >= cols) {
	    std::cout << "Col index out of bounds!" << std::endl;
	}
	return data[row][col];
    }
    // const version of subscript operator for row access
    const int operator() (int row,int col) const {
        if(row < 0 || row >= rows) {
	    std::cout << "Row index out of bounds1" <<std::endl;
	}
	if(col<0 || col > cols) {
	    std::cout << "Col index out of bounds!" << std::endl;
	}
	return data[row][col];
    }

    Array2& operator=(const Array2& left) {
        if(left.data == data) {
	    return *this;
	}
	for(int i = 0 ; i < rows; i++) {
	    delete[] data[i];
	}
	delete[] data;
	rows=left.rows;
	cols=left.cols;
        data = new int*[left.rows];
	for(int i = 0 ; i < rows;++i){
	    data[i] = new int[left.cols];
	    for(int j = 0 ; j < cols;++j) {
	        data[i][j]=left.data[i][j];
	    }
	}   
	return *this;
    } 
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
