#include <iostream>
using namespace std;
void reverse(char * begin, char * end);

int main() 
{
 char orig[50]= "Practice___Makes_Perfect";
 int length=strlen(orig);
 char * begin,*end;
 begin=end=orig;
 while(*end){
 	cout<<*end<<endl;
 	end++;
    	if(*end=='_'||*end=='\0') {
		reverse(begin,end-1);
        begin=end+1;
   		}
   	while(*end=='_'&&*(end-1)=='_'){
        end++;
        begin=end;
        continue;
        }
	}
   	reverse(orig,end-1);
   	cout<<orig<<endl; 
   	return 0;
}
  
   
void reverse(char *begin, char *end)
{
 char temp;
 while(begin<end){
 	temp=*begin;
 	*begin++=*end;
   	*end--=temp;
  	}
}
