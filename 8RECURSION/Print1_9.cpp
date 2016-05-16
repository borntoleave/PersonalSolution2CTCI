//	try g++ Print1_9.cpp
//	./a.out 1 10
#include<iostream>
#include<string>
using namespace std;
int ex(int i,char **j){
	return 0;
}

int main(int argc, char ** argv){
	/*if(argc!=3){
		cerr<<"Format: "<<argv[0]<<" <init> <end>"<<endl;
		exit(-1);}*/
	int (*fun[2])(int, char **)={main,ex};
	char **s=new char *[3];
	s[1]=new char[50];s[2]=new char[50];
	int i=atoi(argv[1]),loop=atoi(argv[2]);
	sprintf(s[1],"%d",i+1);
	sprintf(s[2],"%d",loop);
	cout<<i<<endl;
	fun[i/loop](3,s);	
}


