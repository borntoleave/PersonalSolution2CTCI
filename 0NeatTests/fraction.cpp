//Let the user enter a decimal number. The range allowed is 0.0001 to 0.9999. Only four decimal places are allowed. The output should be an irreducible fraction. 
//Eg: If the user enters 0.35, the irreducible fraction will be 7/20.

#include<iostream>
using namespace std;
int main(int argc, char *argv[])
{
	if(argc<2)	{
		cerr<<argv[0]<<"<decimal# 0.0001>"<<endl;
		exit(-1);
	}
	double num=atof(argv[1]);
	int a=num*10000,b=10000;//format would be a/b
	for (int f=2;f<=5000;f++)
		if(!(a%f)&&!(b%f))	{
			a/=f;
			b/=f;
			f--;
		}
	cout<<num<<" = "<<a<<'/'<<b<<endl;	
}
