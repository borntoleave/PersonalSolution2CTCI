//Goldbach's conjecture : Every even integer greater than 2 can be expressed as the sum of two primes. 
//Write a function which takes a number as input, verify if is an even number greater than 2 and also print atleast one pair of prime numbers.
#include<iostream>
#include<cmath>
#define RANGE 1000
using namespace std;
int isPrime(int n)
{
	for(int i=2;i<=sqrt(n);i++)
		if(!(n%i))
			return 0;
	return 1;
}
int main()
{
	int prime[RANGE/2],count=1,flag;
	prime[0]=2;
	for(int i=3;i<RANGE;i+=2)
		if(isPrime(i))	{
			prime[count++]=i;
			//cout<<i<<endl;
		}
	for(int even=4;even<RANGE;even+=2)	{	
		flag=0;
		for(int c=0;c<count;c++)		{
			if(isPrime(even-prime[c]))	{
				cout<<even<<" = "<<prime[c]<<" + "<<even-prime[c]<<endl;
				flag=1;
				break;
			}
		}
		if(!flag)
			cerr<<even<<" breaks Goldbach's conjecture!"<<endl;
	}
}

