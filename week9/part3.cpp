#include<iostream>
#include<set>
#include<sstream>
#include<vector>
#include<string>

using namespace std;
int main () {
   set<int> s1;
   multiset<int> s2; 
   string input;
   int count=0;
   int commandline=1;
   while(std::getline(cin,input) && commandline > 0) {
     if(count == 0) {
         commandline=std::stoi(input);
	 count++;
	 continue;
     }
     std::vector<string> words;
     std::istringstream iss(input);
     std::string word;
     while(iss>>word) {
         words.push_back(word);
     }
     if(words[0] == "add") {
	 s1.insert(std::stoi(words[1]));
         s2.insert(std::stoi(words[1]));
	 std::cout<< s2.count(std::stoi(words[1]))<<std::endl;
     } else if(words[0] == "del") {
	 std::cout<<s2.count(std::stoi(words[1])) << std::endl;
         s2.erase(std::stoi(words[1]));  
     } else if (words[0] == "ask") {
         int val = std::stoi(words[1]);
         if(s1.find(val) != s1.end()) {
	     std::cout << "1 ,"<< s2.count(std::stoi(words[1])) <<endl;
	 } else {
	     std::cout << "0 ," <<s2.count(std::stoi(words[1])) << endl;
	 }
     }
   }
}
