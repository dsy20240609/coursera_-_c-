#include<iostream>
#include<iomanip>

using namespace std;

int main (int argc, char* argv) {
  int caseNum;	
  cin<<caseNum;
  vector<int> M;
  M.resize(caseNum);
  vector<vector<int>> initalVal;
  initialVal.resize(caseNum);

  struct warriorNode {
    warrior _myType;
    int _myValue;
    warriorNode* _next;
  }；
  enum type {red,blue};
  enum warrior {dragon, ninja, iceman,lion,wolf};
  for(int i = 0 ; i < caseNum;i++) {
    cin<<M[i];
    vector<int> tmp;
    for(int j = 0 ; j < 5; j++) {
      cin<<res;
      tmp.push_back(res);
    }
    initalVal.push_back(tmp);
  }
  for(int i = 0; i < caseNum;i++) {
    std::cout<< "Case:" << i+1<< endl;
    int totalValue=M[i];

    warriorNode* riceman= new warriorNode(iceman,initialVal[i][2],nullptr);
    warriorNode* rlion  = new warriorNode(lion,initialVal[i][3],nullptr);
    warriorNode* rwolf  = new warriorNode(wolf,initialVal[i][4],nullptr);
    warriorNode* rninja = new warriorNode(ninja,initialVal[i][1],nullptr);
    warriorNode* rdragon = new warriorNode(dragon,initialVal[i][0],nullptr);
    riceman->next=rlion;
    rlion->next=rwolf;
    rwolf->next=rninja;
    rninja->next=rdragon;
    rdragon->next=riceman;

    warriorNode* blion=new warriorNode(lion,nullptr);
    warriorNode* bdragon=new warriorNode(dragon,nullptr);
    warriorNode* bninja = new warriorNode(ninja, nullptr);
    warriorNode* biceman = new warriorNode(iceman,nullptr);
    warriorNode* bwolf = new warriorNode(wolf,nullptr);
    blion->next=bdragon;
    bdragon->next=bninja;
    bninja->next=biceman;
    biceman->next=bwolf;
    bwolf->next=blion;

    hq redh= hq(totalValue,red,riceman,0);
    hq blueh=hq(totalValue,blue,blion,0);

    if(redh._curNode)
     
  }


  class hq {
     hq(int value, type t, warriorNode* curNode,int count): _value(value),
	                                                       _type(t),
       							       _curNode(curNode),
       							       _count(0),
                    					       _icemanN(0),
			      				       _lionN(0),
			      				       _wolfN(0),
			      				       _ninjaN(0),
			      				       _dragonN(0) {};
     

  private:
     int _count;
     warriorNode* _curNode;
     int _value;
     type _type;
     int _icemanN;
     int _lionN;
     int _wolfN;
     int _ninjaN;
     int _dragonN;
  }；
  

}
