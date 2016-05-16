#include<iostream>
using namespace std;
int nOfOnes(int opr){
	int c=0;
	while(opr){
		opr&=(opr-1);	
		c++;
	}
	return c;
}
int main(int argc,char *argv[]){
	int a=atoi(argv[1]),b=atoi(argv[2]);
	int opr=a^b;
	cout<<nOfOnes(opr)<<endl;
}
