#include<iostream>
#include<string>
using namespace std;
string reverse(string orig);
void reversePointer(char * begin,char * end);
int main(int argc,char * argv[])
{
if(argc!=2){cerr<<"Fromat: "<<argv[0]<<" <textfile>"<<endl;exit(-1);}//won't use outside file though
string orig="Do or do not, there is no    try.";
cout<<orig<<endl
	<<"reverse->"<<endl;
string rev=reverse(orig);
cout<<rev<<endl;

}


string reverse(string orig)
{
int length=orig.length();
int nWords=0;
int *position=new int [length];
if (length!=0){
	nWords=1;
	position[0]=0;
	}
for(int l=0;l<length;l++)
	if(orig[l]==' ')	
		position[nWords++]=l+1;
for(int w=nWords;w>0;w--)
	{int l=0;
	while(orig[position[w-1]+l]!=' '&&orig[position[w-1]+l]!='\0')
		cout<<orig[position[w-1]+l++];
	cout<<' ';
	}
cout<<endl;

char *s0,*s,*e;
s0=s=e=&orig[0];

for(int l=0;l<length;l++) {
	e++;
	if(*e==' '||*e=='\0')	{
		reversePointer(s,e-1);
		s=e+1;}
	}
reversePointer(s0,e-1);
return orig;
}

void reversePointer(char *s,char *e)
{
char temp;
while (s<e){
	temp=*s;
	*s++=*e;
	*e--=temp;
	}
}


