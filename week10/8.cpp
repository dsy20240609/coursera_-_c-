#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<bitset>
#include<iomanip>
#include<algorithm>

using namespace std;

// used to transfer vector to string
std::string vectorToString(const std::vector<int>& vec) {
    std::stringstream ss;
    for (size_t i = 0; i < vec.size(); ++i) {
        ss << vec[i];
    }
    return ss.str();
}


int main() {
    vector<int> result;
    int count=0;
    int caseNumber =1;
    string input;
    while(std::getline(cin,input) && caseNumber >0) {
	if(count == 0) {
	    caseNumber=std::stoi(input);
	    count++;
	    result.reserve(caseNumber);
            continue;
	}
        istringstream ss(input);
        string word;
        vector<int> words;
        while(ss>>word) {
            words.push_back(stoi(word));
        }
        vector<int> res;
        res.resize(32);
        int tmp =words[0];
	int count=0;
        while(tmp > 0 ) {
            int tmp1 = tmp%2;
            tmp=tmp/2;
            res[count]=tmp1;
	    count++;
        }
        for(int j = 0 ; j < 32; j++) {
            if(j < words[1]) {
                res[j]=0;
            } else if (j == words[1]) {
                continue;
            } else if (j < words[2]) {
                res[j] =1;
            } else if (j == words[2]) {
		int temp1= res[j];
                res[j] = temp1 == 0 ? 1 : 0; 
            } else {
                res[j] =0;
            }     
        }
	// change the display format from binary vector into hex
	std::reverse(res.begin(),res.end());
	string str;
        str=vectorToString(res);
	std::bitset<32> bits(str);
	unsigned long decimal = bits.to_ulong();
	std::stringstream ss1;
	ss1<<std::hex << std::uppercase<<decimal;
        std::string hexStr = ss1.str();
        printf("%s\n",hexStr.c_str());
        caseNumber--;
    }
}
