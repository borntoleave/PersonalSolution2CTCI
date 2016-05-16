#include<iostream>
using namespace std;
string compare(int n1,int n2)
{
return n1^n2?"not equal":"equal";
}
int main(int argc, char *argv[])
{
if (argc!=3){cerr<<"format: "<<argv[0]<<" <num2><num2>"<<endl;exit(-1);}
int n1=atoi(argv[1]),n2=atoi(argv[2]);
cout<<n1<<" and "<<n2<<" are "<<compare(n1,n2)<<"."<<endl;
}
