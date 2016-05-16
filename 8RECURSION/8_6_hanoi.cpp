#include<iostream>
#include<stack>
#include<ctime>
#include<iomanip>
using namespace std;
double ct=0;
int N;
stack<int> s[3];
void print(){
	stack<int> t[3];
	for(int i=0;i<3;i++)
		t[i]=s[i];
	for(int i=0;i<3;i++){
		for(int l=0;l<N-t[i].size();l++)
			cout<<"   ";
		while(!t[i].empty()){
			cout<<setw(3)<<t[i].top();
			t[i].pop();
		}
	cout<<"| stack "<<i<<endl;
	}
	cout<<"-------------------------------------------------------------"<<endl;
}
void hanoi(int n,stack<int> &source,stack<int> &buff,stack<int> &dest){
	if(n<=0)
		return;
	hanoi(n-1,source,dest,buff);
	ct++;
	print();
	dest.push(source.top());
	source.pop();
	hanoi(n-1,buff,source,dest);	
}


int main(int argc,char *argv[])
{
 	if(argc!= 2 ){cerr<<"Format: "<<argv[0]<<" < N > "<<endl;exit(-1);}
 	N=atoi(argv[1]);
	for(int i=N;i>0;i--)	//init
		s[0].push(i);

 	clock_t start=clock();
	
	hanoi(N,s[0],s[1],s[2]);
	cout<<ct<<" steps"<<endl;
 	cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	return 0;
}
