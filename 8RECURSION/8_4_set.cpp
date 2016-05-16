#include<iostream>
#include<string>
#include<stack>
#include<cmath>
using namespace std;

void sub(char *set,int n,string pre){
	if(n==-1){
		cout<<"{"<<pre<<"} ";
		return;
	}
	string local=pre;
	for(int i=n-1;i>=-1;i--){
		if(i>-1)
			local+=set[4-i];
		sub(set,i,local);
		local=pre;
	}
}

stack<string> subbit(char *set,int n){
	stack<string> stk;
	for(int b=0;b<pow(2,n);b++){
		//cout<<b<<endl;
		int i=0,bit=b;string s="";
		while(bit){
			if(bit&1)
				s+=set[i];
			bit>>=1;i++;
		}
		stk.push(s);
	}
	return stk;
}
		
int main(){
	char *set=new char[5];
	for(int i=0;i<5;i++)
		set[i]=i+'a';
	for(int i=0;i<=5;i++)
		cout<<set[i];
	cout<<" subset:"<<endl;
	string s="";
	stack<string> stk=subbit(set,5);
	while(!stk.empty()){
		cout<<"{"<<stk.top()<<"} ";
		stk.pop();
	}
	cout<<endl;

	sub(set,5,"");
	cout<<endl;
	
}
