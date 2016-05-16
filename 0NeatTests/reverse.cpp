//Rz Oct 29, 2015
//reverse an input string
#include<iostream>
#include<string>
using namespace std;

int main(int argc, char *argv[])
{
	if(argc!=2)	{
		cerr<<"Foramt: "<<argv[0]<<" <string>"<<endl;exit(-1);}
	int n=strlen(argv[1]);
	char temp;
	for (int i=0;i<n/2;i++)	{
		temp=argv[1][i];
		argv[1][i]=argv[1][n-i-1];
		argv[1][n-i-1]=temp;
		}
	cout<<argv[1]<<endl;

	char str[5]="zyxn";
	*(str+1)^=*(str+3);
	*(str+3)^=*(str+1);
	*(str+1)^=*(str+3);
	cout<<str<<endl;


}


