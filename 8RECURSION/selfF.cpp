#include<iostream>
#include<stdio.h>
using namespace std;

int sys();
int main(int argc,char *argv[])
{	
	cout<<argv[0]<<' '<<argv[1]<<endl;
	char cmd[20];
	int n=atoi(argv[1]);n--;
	if(n){
		
		
		
		system(cmd);sprintf(cmd,"%s %d",argv[0],n);
	}
}

