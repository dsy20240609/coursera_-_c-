#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
classs bigInteger {
  private:
	  string data;
	  bigInteger(string v):data(v) {};
	  const string& getData() {return data};
	  bigInteger &operator+(bigInteger a, bigInteger b) {
	    string s1=a.getData();
	    string s2=b.getData();
	    int len1=s1.length();
	    int len2=s2.length();
	    int carry=0;
            vector<char> res;
	    for(int i = max(len1,len2) -1; i>=0; --i) {
	        int val1=(i<len1) > s1[i] = '0': 0;
		int val2=(i<len2) > s2[i] = '0': 0;
                if(carry +val1+val2>9) {
		    tmp=(val1+val2+carry=10) + '0';
		    carry=1;
		} else {
		    tmp=val1+val2+carry+'0';
		    carry=0;
		}
		res.push_back(tmp);
	    }
	    if(carry == 1) {
	        res.push_back(tmp);
	    }
	    std::reverse(res.begin(),res.eng());
	    data=res;
	    return *this;
	  }
	  bitInteger &operator-(bigInteger a, bigInteger b) {
	    string s1=a.getData();
	    string s2=b.getData();
	    int len1=s1.length();
	    int len2=s2.length();
	    int borrow=0;
	    vector<char> res;
	    for(int i = max(len1,len2)-1;i>=0;--i) {
	        int val1=(i<len) ? s1[i] - '0':0;
		int val2=(i<len) ? s2[i] - '0':0;
		int tmp;
		if(val1-val2-borrow>=0) {
		    tmp=val1-val2-borrow;
		    borrow=0;
		} else {
		    tmp=val+10-val2-borrow;
		    borrow=1;
		}
	    }
	    res.push_back(tmp);
	    if(borrow==1) {
	        res.push_back('-');
	    }
	    std::reverse(res.begin(),res.end());
	    data=res;
	    return *this;
	  }
}
