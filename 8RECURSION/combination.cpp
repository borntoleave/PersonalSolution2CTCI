#include<iostream>
#define N 4
using namespace std;
int ct=0;
void combination(char *s,char *stk,int * used,int level)
{
 if(level==N)
 	return;
 for(int i=0;i<N;i++){
 	if(used[i])
 		continue;
 	int after=0;
 	for(int j=i;j<N;j++)
 		after+=used[j];
 		if(after)
 		continue;
 	stk[level]=s[i];
 	cout<<stk<<' ';
 	ct++;
 	used[i]=1;
 	combination(s,stk,used,level+1);
 	used[i]=0;
 	stk[level]='\0';
	}
}

void bettercombination(char *s,char *stk,int current,int level)
{
 if(level==N)
 	return;
 for(int i=current;i<N;i++){
 	stk[level]=s[i];
 	cout<<stk<<' ';
 	ct++;
 	bettercombination(s,stk,i+1,level+1);
	stk[level]='\0';
	}

}

int main()
{
 char * s=new char[N], * stk=new char[N];
 int *used=new int[N];
 for(int i=N-1;i>=0;i--){
 	s[N-1-i]=char('z'-i);
	used[i]=0;
 	}
 cout<<s<<endl;
 combination(s,stk,used,0);
 cout<<ct<<endl;
 ct=0;
 bettercombination(s,stk,0,0);
 cout<<ct<<endl;

}

