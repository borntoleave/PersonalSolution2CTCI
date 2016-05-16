//RzL Oct28,2015
//recursively calculate fibonacci sequence. 
//optimized to use dynamic table to reduce calculation
#include<iostream>
using namespace std;
double fib(double *seq,int n);
int main(int argc, char *argv[])
{
 if(argc<2){cerr<<argv[0]<<" <integer>"<<endl;exit(-1);}
 int n=atoi(argv[1]);
 double *seq=new double [n+1]();	//dynamic table
 cout<<"Fibonacci["<<n<<"] = "<<endl<<fib(seq,n)<<endl;
 for(int i=0;i<=n;i++)
 	cout<<seq[i]<<" ";
 cout<<endl;
}

double fib(double *seq,int n)
{
 seq[n]=		n<=1? 
			n:	seq[n]?
				seq[n]:	fib(seq,n-1)+fib(seq,n-2);
 cout <<"find Fibonacci["<<n<<"]\t"<<seq[n]<<endl;
 return seq[n];
}

