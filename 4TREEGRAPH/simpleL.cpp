#include<iostream>
using namespace std;
class nd{
public:
	int data;
	nd *next;
	nd(int d=0):data(d),next(NULL){}
	~nd(){}
};

class lt{
public: 
	nd *head;
	
	lt():head(NULL){}
	void append(int d){
	cout<<"a"<<endl;
	nd *cur=new nd(d);
	if (head==NULL){
		head=cur;
		return;
	}
	nd *it=head;
	while(it->next!=NULL)
		it=it->next;
	it->next=cur;
	}
	void print(){
		nd *it=head;
		while(it){
			cout<<it->data<<'\t';
			it=it->next;
		}

	}
};

int main()
{
 lt l;
 l.append(12);
 l.append(10);
 l.print();



}
