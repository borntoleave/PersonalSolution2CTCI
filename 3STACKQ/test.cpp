#include<iostream>
#include"StkQ.h"


int main(int argc,char *argv[])
{
 if(argc!= 1 ){cerr<<"Format: "<<argv[0]<<" < > "<<endl;exit(-1);}
stk<int> a;
for(int i=3;i<20;i+=2){
a.push(i%7);cout<<a;}
for(int i=0;i<13;i++){
a.pop();
cout<<a;}

//ele<char> *q0=new ele<char>('a');
que<char> q;//(q0);
for(int i=0;i<10;i++)
	q.add(char(2*i+'a'));
cout<<q;
for(int i=0;i<7;i++)
	cout<<q.pop()->getData();
cout<<endl<<q.isEmpty()<<endl;
for(int i=0;i<7;i++)
	cout<<q.pop()->getData();
 return 0;
}
