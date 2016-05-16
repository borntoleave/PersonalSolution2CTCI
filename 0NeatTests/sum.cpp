//sum from 1 to n
#include<iostream>
using namespace std;
int sigma(int n);
int main(int argc,char *argv[])
{
int n = atoi(argv[1]);
cout <<sigma(n)<<endl;
}
int sigma(int n)
{
	cout <<n<<endl;
     return ( n && ( n += sigma(n-1) ), n);
}
