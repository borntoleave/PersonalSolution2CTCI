#include<iostream>
using namespace std;
int rd(){
 	return rand()%40-10;
}
template<class Type>
class node
{
private:
	Type data;
	node *next;
public:
	node(int d=0):data(d),next(NULL){}
	~node(){
		data=0;
		next=NULL;
		}
	Type getData(){return data;}
	void setData(Type d){data=d;}
	node * getNext(){return next;}
	void setNext(node * n){next=n;}
};
template<class Type>
class list
{
private: 
	node<Type> *head;	
public:
	list():head(NULL){}
	node<Type> * getHead(){return head;}
	void append(Type d){
		node<Type> *end=new node<Type>(d);
		node<Type> *itr=head;
		if(head==NULL){
			head=end;
			return;
		}
		while(itr->getNext()!=NULL){
			itr=itr->getNext();
		}
		itr->setNext(end);	
	}
	void prepend(Type d){
		node<Type> *begin=new node<Type>(d);
		begin->setNext(head);
		head	=begin;
	}
	void print(){
		node<Type> *itr=head;
		do{
			cout<<itr->getData()<<" > ";
		}	while((itr=itr->getNext())!=NULL);
		cout<<endl;
	}
//2.1
	void del(Type d){
		node<Type> *itr=head;
		while(itr->getNext()!=NULL&&itr->getNext()->getData()!=d)
			itr=itr->getNext();
		node<Type> *nxt=itr->getNext();
		itr->setNext(itr->getNext()->getNext());
		delete nxt;
	}
	node<Type>* find(Type d){
		node<Type> *itr=head;
		while(itr!=NULL){
			if(itr->getData()==d)
				return itr;
			itr=itr->getNext();
		}
		return NULL;
	}

	void insert(node<Type> *loc,Type d){
		node<Type> *newN=new node<Type>(d);
		newN	->setNext(loc->getNext());
		loc->setNext(newN);
	}
//2.2
	node<Type> * printBack(node<Type> * c,int k,int &i){
		if(c==NULL){
			return NULL;
		}
		printBack(c->getNext(),k,i);
		i++;
		if(i==k)
			cout<<"The "<<k<<"th-to-last element is "<<c->getData()<<endl;
		return c;
		
	}
//2.5
	void initWithArray(Type * arr,int size){
		for(int i=0;i<size;i++)
			append(arr[i]);
		print();
	}
	
	list operator +(list& l){
		cout<<"   ";print();cout<<" + ";l.print();cout<<" = ";
		list<Type> l3;
		node<Type> *p1=head,*p2=l.head;
		int v1,v2,mod,div=0;
		while(p1!=NULL||p2!=NULL){
			v1= p1==NULL ? 0:p1->getData();
			v2= p2==NULL ? 0:p2->getData();
			mod=(v1+v2+div)%10;
			l3.append( mod );
			div=(v1+v2+div)/10;
			if(p1!=NULL)
				p1=p1->getNext();
			if(p2!=NULL)
			p2=p2->getNext();
		}
		if(div)
			l3.append(div);
		l3.print();
		return l3;
	}	
	void reverse(){
		node<Type> *hd,*nx,*tm;
		hd=head;
		nx=hd->getNext();
		while(nx!=NULL){
			tm=nx->getNext();
			nx->setNext(hd);	
			hd=nx;
			nx=tm;
		}
		head->setNext(NULL);
		head=hd;
	}	
};

 


int main(int argc,char *argv[])
{
 if(argc!= 1 ){cerr<<"Format: "<<argv[0]<<" < > "<<endl;exit(-1);}
 list<int> l;
 l.prepend(1);
 l.append(10);
 l.append(5);
 l.append(3);
 l.print();
 l.prepend(2);
 l.print();
 l.del(10);
 l.print();
 node<int> *location=l.find(5);
 location->setData(11);
 l.print();
 for(int i=0;i<10;i++)
 	l.append(rd());
  l.print();
 int i;
 l.printBack(l.getHead(),5,i);
//2.5
 list<int> l1,l2,l3,l4,sum;
 int lv1[3]={7,1,6},lv2[3]={5,9,2},lv3[4]={5,9,3,1},lv4[5]={5,9,3,5,1};
 l1.initWithArray(lv1,sizeof(lv1)/sizeof(int));
 l2.initWithArray(lv2,sizeof(lv2)/sizeof(int));
 l3.initWithArray(lv3,sizeof(lv3)/sizeof(int));
 l4.initWithArray(lv4,sizeof(lv4)/sizeof(int));
 l1+l2;
 l1+l3;
 l1+l4;
 l3+l4;
 l.reverse();
 l.print();
 l4.insert(l4.find(9),11);
 l4.print();
 l4.del(11);
 l4.print();
 
 return 0;
}
