#include"StkQ.h"
template<class Type>
class Q{
 private:
 	stk<Type> fr,bk;
 public:
 	Q(){}
 	~Q(){}
 void push(Type d){
 	bk.push(d);
 }
 Type pop(){
	if(fr.isEmpty()&&bk.isEmpty()){
		cerr<<"empty!"<<endl;
		return 0;
		}
	if(fr.isEmpty())
		shift();
	return fr.pop()->getData();
 }
 void shift(){
	while(!bk.isEmpty())
		fr.push(bk.pop()->getData());
 }
};

int main(){
 Q<int> q;
 for(int i=0;i<10;i++){
 	cout<<i<<' ';
	q.push(i);
	}
 cout<<endl;
 for(int i=0;i<5;i++){
 	cout<<q.pop()<<' ';
	}
 cout<<endl;
 for(int i=0;i<5;i++){
 	cout<<2*i<<' ';
 	q.push(2*i);
	}
 cout<<endl;
 for(int i=0;i<11;i++)
 	cout<<q.pop()<<' ';
 cout<<endl;
}
