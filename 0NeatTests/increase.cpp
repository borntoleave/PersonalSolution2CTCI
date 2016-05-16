//Given n. Generate all numbers with number of digits equal to n, such that the digit to the right is greater than the left digit (ai+1 > ai). E.g. if n=3 (123,124,125,……129,234,…..789)
#include<iostream>
#include<cmath>
using namespace std;
int main(int argc, char *argv[])
{
	if(argc<2)	{
		cerr<<argv[0]<<" <digits>"<<endl;
		exit(-1);
	}
	int digits=atoi(argv[1]),flag,a,b;
	for(int n=pow(10,digits-1);n<pow(10,digits);n++)	{
		flag=1;
		int tmp=n;
		for(int i=0;i<digits;i++)	{
			b=tmp%10;
			tmp/=10;
			a=tmp%10;
			if(a>=b)	{
				flag=0;
				break;
			}
		}
		if(flag==1)
			cout<<n<<'\t';
	}
	cout<<endl;
}
