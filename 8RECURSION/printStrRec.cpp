#include<iostream>
using namespace std;
void print(char *s,char direction)
{
if (*s!='\0') {
	if(direction=='+') {
		cout<<*s;
		print(s+1,'+');
		}
	else if(direction=='-') {
		print(s+1,'-');
		cout<<*s;
		}
	}
}

int main()
{
char str[50]="Hello world!";
print(str,'+');
cout<<endl;
print(str,'-');
cout<<endl;
}
