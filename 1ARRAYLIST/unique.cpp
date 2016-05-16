#include<iostream>

using namespace std;

bool unique(char * s){
 int counter=0,idx=0;
while(s[idx]!='\0'){
 	int bit=int(s[idx]-'a');
 	if(counter&1<<bit){
 		return false;
 	}
 	counter |= (1<<bit);
 	idx++;
 }
 return true;
}

int main(int argc,char *argv[])
{
 if(argc!= 2 ){cerr<<"Format: "<<argv[0]<<" <string> "<<endl;exit(-1);}

 cout<<unique(argv[1])<<endl;;
 return 0;
}
