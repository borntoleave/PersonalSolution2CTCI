#include<iostream>
using namespace std;
void paren(char * p,int n,int left,int used,int cur){
	if(cur==2*n){
		for(int i=0;i<2*n;i++)
			cout<<p[i];
		cout<<endl;
		return;
	}
	if(left==0||used<n){
		p[cur]='(';
		paren(p,n,left+1,used+1,cur+1);
		}
	if(left>0){
		p[cur]=')';
		paren(p,n,left-1,used,cur+1);}
}


int main(int argc, char * argv[]){
	if(argc!=2){
		cerr<<"Format: "<<argv[0]<<"<N pairs>"<<endl;
		exit(-1);
	}
	int n=atoi(argv[1]);
	char * p=new char [2*n];
	paren(p,n,0,0,0);

}
