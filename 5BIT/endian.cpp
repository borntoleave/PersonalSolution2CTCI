#include<iostream>
using namespace std;
int main(){
	char a='a',b='b',c;
	c=b-a;
	c>>=1;
	cout<<int(c)<<endl;//0 for big endian
}
