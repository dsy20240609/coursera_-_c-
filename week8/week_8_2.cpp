#include<list>
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<sstream>

using namespace std;

int main () {
    int commandline =0;
    int count=0;
    vector<list<int>> res;
    res.resize(10000);
    std::string command;
    while(std::getline(std::cin,command)) {
	if(count == 0) {
            commandline=std::stoi(command);
	    count++;
	    continue;
	}
	printf("command is %s\n",command.c_str());
	std::istringstream iss(command);
	std::vector<std::string> words;
	std::string word;
	while(iss>>word) {
	  words.push_back(word);
	}
	printf("words size is %d\n", words.size());
        if(words[0] == "new") {
            printf("line 25 %s \n",words[1].c_str());
	    int id = std::stoi(words[1]);
	    printf("line 27\n");  
	    res[id-1] = list<int> {};
	    printf("line 29\n");
	    commandline--;
	} else if (words[0] == "add") {
	    int id = std::stoi(words[1]);
	    int num = std::stoi(words[2]);
	    res[id-1].push_back(num);
	    commandline--;
	} else if (words[0] == "out") {
	    int id = std::stoi(words[1]);
            list<int> tmp=res[id-1];
	    tmp.sort();
            list<int>::iterator it;
	    for(it= tmp.begin(); it != tmp.end(); it++) {
	        std::cout<< *it << " ";
	    }
	    std::cout<<endl;
	    commandline--;
	} else if (words[0] == "merge") {
	    int id1= std::stoi(words[1]);
	    int id2= std::stoi(words[2]);
	    list<int>::iterator it;
	    list<int> tmp= res[id2-1];
	    for(it = tmp.begin(); it !=tmp.end();++it) {
	        res[id1-1].push_back(*it);
	    }
	    while(!res[id2-1].empty()) {
	        res[id2-1].pop_back();
	    }
	    commandline--;
	} else if (words[0] == "unique") {
            int id =std::stoi(words[1]);
            list<int>::iterator it;
            set<int> tmp;
	    list<int> newlist;
            if(res[id-1].size() <=1 ) {
	        continue;
	    } else {
	        for(it = res[id-1].begin(); it != res[id-1].end(); ++it) {
		    tmp.insert(*it);
		}
		set<int>::iterator iter1;
		for(iter1= tmp.begin(); iter1!=tmp.end(); ++iter1) {
		    newlist.push_back(*iter1);
		}
		res[id-1]=newlist;
	    }
	    commandline--;
	}	   
    }
}

