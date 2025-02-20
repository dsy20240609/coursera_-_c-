#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<initializer_list>

template <typename T>
T max(std::initializer_list<T> values) {
    return *std::max_element(value.begin(), values.end());
}

using namespace std;

string copy(vector<string>& s, int n, int x, int l) {
  string res= s[n];
  return substr(res,x,l);
}

string add(string s1, string s2) {
   if(std::stoi(s1) >=0 && std::stoi(s2) <= 99999 && std::stoi(s2) >=0 && std::stoi(s2) <= 99999) {
       return std::to_string(std::stoi(s1) + std::stoi(s2));    
   } else {
       return s1+s2;
   }
}

int find(string s, string n) {
    std::size_t found = n.find(s);
    if(found != std::string::npos) {
        return found
    } else {
        return n.length();
    }
}

int rfind(string s, string n) {
    std::size_t found=n.rfind(s);
    if(found !=std::string::npos) {
        return found;
    } else {
        return n.length();
    }
}

void insert(vector<string>& svector, string s ,int n, int x) {
    svector[n].insert(x,s); 
}
void reset(vector<string>& svector, int n ,string s) {
    svector[n]=s;
}

void printN(vector<string> & svector, int n) {
    if(n >= svector.size()) {
        std::cout << "index out of string vector bound!" <<endl;
    }
    std::cout << svector[n] <<std::endl;
}
void printall(vector<string> &svector) {
    for(int i = 0 ; i < svector.size(); i++) {
        std::cout<< svector[i] << endl;
    }
}



int main() {
    std::string input;
    int count=0;
    int N=0;
    vector<string> strV;
    while(true) {
        std::cin>>input;
	if(input == "over") {
	    break;
	}
        if(count =0) {
	   N=std::stoi(input);
           count++;
           continue;	   
	} else if(count < N+1) {
	    strV.push_back(input);
	} else {
	  // vector<string> result;
          // std::istringstream iss(str);
	  // std::string word;
	  // while(iss>>word) {
	  //     result.push_back(word);
	  // }
	  string tmp=input;
	  while(tmp.size()>0) {
	      size_t found1=tmp.find_last_of("copy");
	      size_t found2=tmp.find_last_of("add");
	      size_t found3=tmp.find_last_of("find");
	      size_t found4=tmp.find_last_of("rfind");
	      size_t found5=tmp.find_last_of("insert");
	      size_t found6=tmp.find_last_of("reset");
	      size_t found7=tmp.find_last_of("printN");
	      size_t found8=tmp.find_last_of("printall");
	      if(found1 == max({found1,found2,found3,found4,found5,found6,found7,found8})) {
	        string afterfound= tmp.substr(found1);
	        vector<string> splitCommand;
		std::istringstream iss(afterfound);
		std::string word;
		while(iss>>word) {
		   splitCommand.push_back(word);
		}
                copy()
	
	      } else if (found2 == max({found1,found2,found3,found4,found5,found6,found7,found8})) {
	      
	      } else if (found3 == max({found1,found2,found3,found4,found5,found6,found7,found8})) {
	      
	      } else if (found4 == max({found1,found2,found3,found4,found5,found6,found7,found8})) {
	      
	      } else if (found5 == max({found1,found2,found3,found4,found5,found6,found7,found8})) {
	      
	      } else if (found6 == max({found1,found2,found3,found4,found5,found6,found7,found8})) {
	      
	      } else if (found7 == max({found1,found2,found3,found4,found5,found6,found7,found8})) {
	      
	      } else if (found8 == max({found1,found2,found3,found4,found5,found6,found7,found8})) {
	      
	      } 
	
	}
    
    
    }
    return 0;
}
