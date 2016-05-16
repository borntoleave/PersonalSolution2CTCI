//RzL Jan 5,2015
//recursively calculate fibonacci sequence
#include<iostream>
using namespace std;
double fib(int n);
int main(int argc, char *argv[])
{
 if(argc<2){cerr<<argv[0]<<" <integer>"<<endl;exit(-1);}
 int n=atoi(argv[1]);
 cout<<"Fibonacci["<<n<<"] = "<<endl<<fib(n)<<endl;
}

double fib(int n)
{
 int x=	n<=1?
 		n:	fib(n-1)+fib(n-2);
 cout <<x<<">";
 return x;
}

