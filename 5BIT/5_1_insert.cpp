#include<iostream>
#include<cmath>
using namespace std;

string convert(int n,int base){
	int orig=n>=0?n:(~n+1);
	string s="";
	char b16[]={'A','B','C','D','E','F'};
	while (orig>1){
		char dig=(orig%base>10?b16[orig%base-10]:orig%base+'0');
		s+=dig;
		orig/=base;
	}
	if(n<0)
		s+="-";
	if(base==16)
		s+="x0";
	int len=s.length();
	for(int i=0;i<len/2;i++){
		s[i]^=s[len-i-1];
		s[len-i-1]^=s[i];
		s[i]^=s[len-i-1];
	}
	return s;
}

void insert(long m,long &n,int i,int j){
	if(pow(2,j-i+1)-1<m)
		cerr<<"can't insert!"<<endl;
	int mask=~0;
	mask=mask<<(j+1);
	mask|=((1<<i)-1);
	cout<<convert(mask,2)<<endl;
	n&=mask;
	n|=(m<<i);
}


int b2d(long b){
	int digit=0,n=0;
	while(b){
		int d=b%10;
		n+=d<<digit++;
		b/=10;
	}
	return n;
}

int main(){
 	long m=10011,n=1<<10;
	insert(b2d(m),n,2,6);
	cout<<convert(n,2)<<endl;

}
