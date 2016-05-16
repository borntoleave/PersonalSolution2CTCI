//Given n. Generate all numbers with number of digits equal to n, such that the digit to the right is greater than the left digit (ai+1 > ai). E.g. if n=3 (123,124,125,……129,234,…..789)

#include<iostream>
using namespace std;

void printnum(int *num,int digits)
{
	if(digits<1)		{
		cout<<num[0]<<num[1]<<[2]<<endl;
		return;
	}
	for(int i=num[digits-1])
	
}


int main(int argc,char *argv[])
{
	if(argc<2)	{
		cerr<<argv[0]<<" <digits>"<<endl;
		exit(-1);
	}
	int digits=atoi(argv[1]);
	int *num=new int [digits];
	num[0]=9;
	printnum(num,digits);
}
