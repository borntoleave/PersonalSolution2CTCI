#include<iostream>
using namespace std;
int longest(int n){
	int max=0,pre=0,cur=0;
	if(~n==0)
		return 8*sizeof(int);
	while(n){
		printf("%x\n",n);
		if((n&1)==1)
			cur++;
		else{
			pre= (n&2)==0?0:cur;
			cur=0;
		}
		max=(cur+pre+1)>max?(cur+pre+1):max;
		n>>=1;
	}
	return max;
}


int main(){
	int n=1775;
	cout<<longest(n)<<endl;
	cout<<longest(0x1fffffff)<<endl;
}
