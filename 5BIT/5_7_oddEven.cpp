#include<iostream>
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

int main(int argc, char *argv[]){
	int n=atoi(argv[1]);

	cout<<convert(n,2)<<endl;
	cout<<sizeof(int)<<endl;//int has 32 bits
	int mask=0;
	for(int i=0;i<sizeof(int)*8;i+=2)
		mask|=(1<<i);
	cout<<convert(mask,2)<<endl;
	int mask2=0x55555555;
	
	cout<<convert(mask2,2)<<endl;
	int odd=n&(mask<<1),even=n&mask;
	int swap=(odd>>1)|(even<<1);
	cout<<convert(swap,2)<<endl;



}
