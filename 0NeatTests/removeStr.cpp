//remove characters in a string
#include<iostream>
using namespace std;
string rmChars(string str,string remove);
int main(int argc, char * argv[])
{
if (argc!=3){cerr<<"Format: "<<argv[0]<<" <origStr> <remove>"<<endl;exit(-1);}
cout<<"remove \""<<argv[2]<<"\" from \""<<argv[1]<<"\""<<endl;
rmChars(argv[1],argv[2]);
cout<<argv[1]<<endl;
}

string rmChars(string str,string remove)
{
int *check=new int[128];
for(int i=0;i<128;i++)
	check[i]=0;
int rmLength=0;
while(remove[rmLength]!='\0')
	check[int(remove[rmLength++])]=1;
int source,dest;
source=dest=0;
while(str[source]!='\0'){
	str[dest++]=str[source++];
	if(check[int(str[source-1])])
		dest--;
	}
str[dest]='\0';
return str;
}
