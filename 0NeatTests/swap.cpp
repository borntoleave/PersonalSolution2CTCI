#include<iostream>
using namespace std;
void swap1(int &a,int &b){
	int temp=a;
	a=b;b=temp;
}

void swap2(int &a,int &b){
	if(a==b)
		return;
	a^=b;
	b^=a;
	a^=b;
}

int main(){

int *a=new int[2];
a[0]=5;a[1]=9;
cout<<a[0]<<"\t"<<a[1]<<endl;
swap1(a[0],a[1]);
cout<<a[0]<<"\t"<<a[1]<<endl;
swap2(a[0],a[0]);
cout<<a[0]<<"\t"<<a[1]<<endl;
}
