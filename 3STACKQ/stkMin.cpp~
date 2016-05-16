#include"StkQ.h"
#include<ctime>
template<class Type>
class stkM:public stk<Type>{
 private:
 	stk<Type> min;

 public:
 	stkM():stk<Type>(),min(NULL){}
 	~stkM(){}
 	void pushM(Type d){
 		if(min.isEmpty()||min.peek()>=d){
 			min.push(d);
			cout<<"push to min"<<endl;
 		}
 		this->push(d);
 	}
 	Type popM(){
 		if(this->top==NULL){
			cerr<<"Empty!"<<endl;
			return 0;
 		}
 		if(this->peek()==min.peek())
 			min.pop();
 		return this->pop()->getData();
 	}
 	Type getMin(){
		return min.peek();
 	}
};

int main(){
 srand(time(NULL));
 stkM<int> sm;
 for(int i=0;i<10;i++)
 	sm.pushM(rand()%10);
 sm.pushM(0);
 for(int i=0;i<5;i++)
 	sm.pushM(rand()%10);
 sm.pushM(0);
  for(int i=0;i<3;i++)
 	sm.pushM(rand()%10);
 cout<<sm;
 for(int i=0;i<20;i++)
 cout<<"poping "<<sm.popM()<<", "<<sm<<"\t\t\t\t\tcurrent min: "<<sm.getMin()<<endl;


}
