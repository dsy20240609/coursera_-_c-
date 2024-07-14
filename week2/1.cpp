#include<string>
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

std::vector<std::string> splitString(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
class Student {
  public:
	  Student(std::string name,int age,std::string id, int grade1,int grade2, int grade3, int grade4) : name(name),
	  											age(age),
												id(id),
												grade1(grade1),
												grade2(grade2),
												grade3(grade3),
												grade4(grade4) {}
	  std::string& getName() {return name;}
	  int getAge() {return age;}
	  std::string& getId()   {return id;}
	  int getAverage() {return (grade1+grade2+grade3+grade4)/4;}

  private:
	  std::string name;
	  int age;
	  std::string id;
	  int grade1;
	  int grade2;
	  int grade3;
	  int grade4;
};

int main() {
    std::string input;
    cin>>input;
    char delimiter = ',';
    std::vector<std::string> result = splitString(input, delimiter);
    std::string name=result[0];
    int age = std::stoi(result[1]);
    string id=result[2];
    int grade1=std::stoi(result[3]);
    int grade2=std::stoi(result[4]);
    int grade3=std::stoi(result[5]);
    int grade4=std::stoi(result[6]);

    Student s(name,age,id,grade1,grade2,grade3,grade4);
    std::cout<< s.getName()<< ","<<s.getAge()<< ","<<s.getId()<< ","<<s.getAverage()<<endl;
    return 0;
}
