#include<iostream>
#include<string>
#include<vector>

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
        return found;
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
	   vector<string> splitCommand= ;

	
	}
    
    
    }
    return 0;
}
