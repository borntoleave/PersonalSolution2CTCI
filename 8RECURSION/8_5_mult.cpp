#include<iostream>
#include<ctime>
using namespace std;

int mult(int a,int b){
	int m=0;int bit=0;
	while(b){
		if(b&1){
			m+=(a<<bit);
		}
		bit++;b>>=1;
	}
	return m;
}

void swap(int &a,int &b){
	if(a==b)	
		return;
	a^=b;
	b^=a;
	a^=b;
}

int add(int a,int b){
	if(b==0)
		return a;
	if(b>a)swap(a,b);
	int carry=(a&b)<<1;
	int raw=a^b;
	return add(raw,carry);
}

int main(){
	srand(time(NULL));
	int a=rand()%20+5,b=rand()%20+5;
	cout<<a<<" x "<<b<<" = "<<a*b<<endl;
	cout<<a<<" x "<<b<<" = "<<mult(a,b)<<endl;

	cout<<a<<" + "<<b<<" = "<<a+b<<endl;
	cout<<a<<" + "<<b<<" = "<<add(a,b)<<endl;
}
