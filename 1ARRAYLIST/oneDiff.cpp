#include<iostream>
#include<cstring>
int max(int a,int b)
{
 return a>b?a:b;
}
using namespace std;
int main(int argc,char *argv[])
{
 if(argc!= 3 ){
 	cerr<<"Format: "<<argv[0]<<" <argv[1]> <argv[2]> "<<endl;
 	exit(-1);
 	}
 int l1=strlen(argv[1]),l2=strlen(argv[2]);
 if(abs(l1-l2)>1){
 	cout<<"False"<<endl;exit(0);}
 for(int i=0;i<max(l1,l2);i++){
 	if(*(argv[1]+i)=='\0'||*(argv[2]+i)=='\0'){
 		cout<<"True"<<endl;
 		break;}
 	if(*(argv[1]+i)==*(argv[2]+i))
 			continue;
 	else{
		if(!strcmp(argv[1]+i+1,argv[2]+i+1)
		||!strcmp(argv[1]+i,argv[2]+i+1)
		||!strcmp(argv[1]+i+1,argv[2]+i)){
			cout<<"True"<<endl;
			break;
			}
		else{
			cout<<"False"<<endl;
			break;
			}
 		}
 	}
 return 0;
}

