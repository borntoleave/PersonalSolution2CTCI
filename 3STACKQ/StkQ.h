#include<iostream>
using namespace std;
template <class Type>
class ele{
 protected:
	Type data;
	ele * next;
 public:
	ele(Type d=NULL):data(d),next(NULL){	}
	void setData(Type d){data=d;}
	void setNext(ele * n){next=n;}
	Type getData(){return data;}
	ele * getNext(){return next;}
};

template <class Type>
class stk{
 protected:
	ele<Type> * top;
 public:
 	stk(ele<Type> *t=NULL):top(t){}
 	~stk(){}
	void push(Type d){
		ele<Type> * node=new ele<Type>(d);
		node->setNext(top);
		top=node;
	}
	ele<Type> * pop(){
		if(top==NULL){
			cerr<<"Empty stk!"<<endl;
			return NULL;
		}
		ele<Type> * node=top;
		top=top->getNext();
		return node;
	}
	Type peek(){
		if(top==NULL){
			cerr<<"Empty stk!"<<endl;
			return 0;
		}
		return top->getData();
	}
	bool isEmpty(){
		return top==NULL;
 	}
 	void sort(){
		stk<Type> t2;
		while(!isEmpty()){
			Type cur=pop()->getData();
			if(t2.isEmpty())
			t2.push(cur);
			else{
				while(t2.peek()>cur){
					push(t2.pop()->getData());
				}
			t2.push(cur);
			}
		}
	top=t2.top;
 	} 
	
 friend ostream & operator << (ostream & o,stk<Type> &s){
	ele<Type> *cur=s.top;
	while (cur!=NULL){
		o<<cur->getData()<<" ";
		cur=cur->getNext();}
	o<<endl;
 	return o;
	}
};

template<class Type>
class que{
 protected:
 	ele<Type> *first;
 	ele<Type> *last;
 public:
 	que(ele<Type> *n=NULL):first(n),last(n){}
 	~que(){}
 	void add(Type d){
		ele<Type> *node=new ele<Type>(d);
		if(last!=NULL)
			last->setNext(node);
		last=node;
		if(first==NULL)
			first=last;
 	}
 	ele<Type> * pop(){
		if(first==NULL){
			cerr<<"Empty queue!"<<endl;
			return NULL;
			}
		ele<Type> * node=first;
		first=first->getNext();
		if(first==NULL)
			last=NULL;
		return node;
 	}
 	bool isEmpty(){
		return first==NULL;
 	} 	
 friend ostream & operator << (ostream & o,que<Type> &s){
	ele<Type> *cur=s.first;
	while (cur!=NULL){
		o<<cur->getData()<<" ";
		cur=cur->getNext();}
	o<<endl;
 	return o;
	}
};
