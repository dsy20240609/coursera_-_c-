//*** Peking University C++ Program Design Class Homework**//
//*** Shuyuan Du *******//
//*** 06/15/2024 *******//
//**********************//
#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

enum warriorType {dragon, ninja, iceman,lion,wolf};
enum hqType      {red,blue};

class warriorNode {
public:
	warriorNode(warriorType type, int value): _type(type),
	            _value(value),
                _next(nullptr),
				_prev(nullptr) {};
			
    int getNodeValue()                {return _value;}
	warriorType getWarriorType()      {return _type;}
	//int getWarriorId()                {return _id}
	warriorNode* & getNextWarriorNode() {return _next;}
	warriorNode* & getPrevWarriorNode() {return _prev;}

private:	
    int           _value;
    warriorType   _type;
    //int           _id;
    warriorNode*  _next;
    warriorNode*  _prev;
};

class hq {
public:
     hq(int value, hqType type, warriorNode* curNode, warriorNode* list): _value(value),
	                                   _type(type),
       							       _curNode(curNode),
									   _list(list), 
                    				   _icemanN(0),
			      				       _lionN(0),
			      				       _wolfN(0),
			      				       _ninjaN(0),
			      				       _dragonN(0),
                   					   _active(true) {};
									   
	bool isActive()             {return _active;}
	void setInActive()          {_active = false;}
	warriorNode* getCurList()   {return _list;}
        warriorNode* getCurNode()   {return _curNode;} 
	hqType getHqType()          {return _type;}
	int& getHqValue()           {return _value;}
	int& getIcemanNumber()      {return _icemanN;}
	int& getLionNumber()        {return _lionN;}
	int& getWolfNumber()        {return _wolfN;}
	int& getDragonNumber()      {return _dragonN;}
	int& getNinjaNumber()       {return _ninjaN;}
	 
  private:
     int           _value;
     hqType        _type;
     warriorNode*  _curNode;
	 warriorNode*  _list;
     int           _icemanN;
     int           _lionN;
     int           _wolfN;
     int           _ninjaN;
     int           _dragonN;
	 bool          _active;
};
  
bool canProduceWarrior(hq& curhq);
void produceWarrior(hq& curhq, int time);

int main (int argc, char* argv) {
// get input from stdin	
  int caseNum;	
  cin>>caseNum;
  vector<int> M;
  M.resize(caseNum);
  vector<vector<int>> initialVal;
  //initialVal.resize(caseNum); if i resize here and later push back, the value will be added to the end of the vector.
  for(int i = 0 ; i < caseNum;i++) {
    cin>>M[i];
    vector<int> tmp;
    int res;
    for(int j = 0 ; j < 5; j++) {
      cin>>res;
      tmp.push_back(res);
    }
    initialVal.push_back(tmp);
  }
  
  for(int i = 0; i < caseNum;i++) {
    std::cout<< "Case:" << i+1<< endl;
	int time =0;
    int totalValue=M[i];
printf("line 99 %d \n", initialVal.size());
// create cyclic list for red headquarter
    warriorNode* riceman = new warriorNode(iceman,initialVal[i][2]);
    warriorNode* rlion   = new warriorNode(lion,initialVal[i][3]);
    warriorNode* rwolf   = new warriorNode(wolf,initialVal[i][4]);
    warriorNode* rninja  = new warriorNode(ninja,initialVal[i][1]);
    warriorNode* rdragon = new warriorNode(dragon,initialVal[i][0]);
printf("line 106\n");
    riceman->getNextWarriorNode()=rlion;
    rlion->getNextWarriorNode()=rwolf;
    rwolf->getNextWarriorNode()=rninja;
    rninja->getNextWarriorNode()=rdragon;
    rdragon->getNextWarriorNode()=riceman;
printf("line 113\n");
    riceman->getPrevWarriorNode() =rdragon;
    rdragon->getPrevWarriorNode() = rninja;
    rninja->getPrevWarriorNode() = rwolf;
    rwolf->getPrevWarriorNode() = rlion;
    rlion->getPrevWarriorNode() = riceman;
printf("line 118\n");
    warriorNode* curR=riceman;
	
// create cyclic list for blue headquarter
    warriorNode* blion   = new warriorNode(lion,initialVal[i][3]);
    warriorNode* bdragon = new warriorNode(dragon,initialVal[i][0]);
    warriorNode* bninja  = new warriorNode(ninja, initialVal[i][1]);
    warriorNode* biceman = new warriorNode(iceman,initialVal[i][2]);
    warriorNode* bwolf   = new warriorNode(wolf,initialVal[i][4]);
printf("line 127\n");
    blion->getNextWarriorNode()=bdragon;
    bdragon->getNextWarriorNode()=bninja;
    bninja->getNextWarriorNode()=biceman;
    biceman->getNextWarriorNode()=bwolf;
    bwolf->getNextWarriorNode()=blion;
printf("line 133\n");	
    blion->getPrevWarriorNode() = bwolf;
    bwolf->getPrevWarriorNode() = biceman;
    biceman->getPrevWarriorNode()=bninja;
    bninja->getPrevWarriorNode() = bdragon;
    bdragon->getPrevWarriorNode() = blion;	
	
printf("line 140\n");	
	warriorNode* curB=blion;
	
// create read head quarter and blue head quarter to produce warriors

    hq redh= hq(totalValue,hqType::red, curR, riceman);
    hq blueh=hq(totalValue,hqType::blue, curB, blion);
printf("line 147\n");

	while(canProduceWarrior(redh) ||
	      canProduceWarrior(blueh)) {
	    if(canProduceWarrior(redh)) {
                  produceWarrior(redh,time);	
            } else if(redh.isActive()) {
		  std::cout<< time << " red headquarter stops making warriors" << endl;	
		  redh.setInActive();	
	    } 
            if(canProduceWarrior(blueh)) {
	          produceWarrior(blueh,time);	
	    } else if(blueh.isActive()) {
		  std::cout<< time << " blue headquarter stops making warriors" << endl;
                  blueh.setInActive();			  
	    }			
	  time++;
	}
printf("line 165\n");
  }
}

bool canProduceWarrior(hq & headquarter) {
  warriorNode* curList = headquarter.getCurList();
  warriorNode* curNode = headquarter.getCurNode();
  while (curList != nullptr) {
    if(headquarter.getHqValue() >= curNode->getNodeValue()) {
	  return true;	
    } else {
      warriorNode* prev = curNode->getPrevWarriorNode();
      warriorNode* next = curNode->getNextWarriorNode();	
      if(prev == nullptr && next == nullptr) {
		  delete curNode;
	  } else {	  
        prev->getNextWarriorNode()=next;
        delete curNode;
        curNode=next;
      }		
    }	  
  }
  return false;  
}

void produceWarrior(hq & headquarter, int time) {
  headquarter.getHqValue() = headquarter.getHqValue()-headquarter.getCurNode()->getNodeValue();
  warriorNode * curNode = headquarter.getCurNode();
  switch(headquarter.getCurNode()->getWarriorType()) {
	  case  warriorType::lion:
                 headquarter.getLionNumber()=headquarter.getLionNumber()+1;		
                 if(headquarter.getHqType() == hqType::red) {
                     std::cout << time << " red lion " << ++time << "born with strength " << curNode->getNodeValue() << "," <<
                     headquarter.getLionNumber() << "lion in red headquarter\n";
	        	 } else {
	        		 std::cout << time << " blue lion " << ++time << "born with strength " << curNode->getNodeValue() << "," <<
                     headquarter.getLionNumber() << "iion in blue headquarter\n"; 
	        		 
	        	 }        
	  case warriorType::dragon:
               headquarter.getDragonNumber()=headquarter.getDragonNumber()+1;		
               if(headquarter.getHqType() == hqType::red) {
                   std::cout << time << " red dragon " << ++time << "born with strength " << curNode->getNodeValue() << "," <<
                   headquarter.getDragonNumber() << "dragon in red headquarter\n";
	      	 } else {
	      		 std::cout << time << " blue lion " << ++time << "born with strength " << curNode->getNodeValue() << "," <<
                   headquarter.getDragonNumber() << "dragon in blue headquarter\n"; 
	      	 } 
		 
	  case warriorType::iceman:
	         headquarter.getIcemanNumber()=headquarter.getIcemanNumber()+1;		
             if(headquarter.getHqType() == hqType::red) {
                 std::cout << time << " red iceman " << ++time << "born with strength " << curNode->getNodeValue() << "," <<
                 headquarter.getDragonNumber() << "iceman in red headquarter\n";
	    	 } else {
	    		 std::cout << time << " blue iceman " << ++time << "born with strength " << curNode->getNodeValue() << "," <<
                 headquarter.getDragonNumber() << "iceman in blue headquarter\n"; 
	    	 } 
	  case warriorType::wolf:
	     headquarter.getWolfNumber()=headquarter.getWolfNumber()+1;		
         if(headquarter.getHqType() == hqType::red) {
             std::cout << time << " red wolf " << ++time << "born with strength " << curNode->getNodeValue() << "," <<
             headquarter.getDragonNumber() << "wolf in red headquarter\n";
		 } else {
			 std::cout << time << " blue wolf " << ++time << "born with strength " << curNode->getNodeValue() << "," <<
             headquarter.getDragonNumber() << "wolf in blue headquarter\n"; 
		 }
	  case warriorType::ninja:
		 headquarter.getNinjaNumber()=headquarter.getNinjaNumber()+1;		
         if(headquarter.getHqType() == hqType::red) {
             std::cout << time << " red ninja " << ++time << "born with strength " << curNode->getNodeValue() << "," <<
             headquarter.getDragonNumber() << "ninja in red headquarter\n";
		 } else {
			 std::cout << time << " blue ninja " << ++time << "born with strength " << curNode->getNodeValue() << "," <<
             headquarter.getDragonNumber() << "ninja in blue headquarter\n"; 
		 }
  }
}
