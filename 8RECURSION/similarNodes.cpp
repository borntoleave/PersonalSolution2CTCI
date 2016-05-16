#include<iostream>
#include<fstream>
#include<cmath>
using namespace std; 
int **link;//show dynamiclly how the links are built;

int isClose( int i,int j,int T);
int isAncestor(int p,int c,int N,int **tr);
int main(int argc, char *argv[])
{
if(argc!=2)		{cerr<<"Format: "<<argv[0]<<" <input>"<<endl;exit(-1);}
ifstream f(argv[1],ios::in);
if (f.fail())	{cerr<<"Fail to open input file!"<<endl;exit(-2);}
int N,T;
f>>N>>T;
int maxNodes=1;
int **tr=new int *[N-1];
for(int l=0;l<N-1;l++)	{
	tr[l]=new int [2];
	for(int i=0;i<2;i++)		{
		f>>tr[l][i];
		if (tr[l][i]>maxNodes)
			maxNodes=tr[l][i];
			}		//store the tree structure and find the total nodes
	}
cout <<N-1<<" tree links.\tT="<<T<<".\t"<<maxNodes<<" nodes."<<endl;
for(int i=1;i<=maxNodes;i++)	{
	for(int j=1;j<=maxNodes;j++)	//have to go through all pairs to include indirect pairs
	 	if(i!=j)		{
	 		cout<<i<<'\t'<<j;
	 		if(isClose(i,j,T)&&
	 		isAncestor(i,j,N-1,tr))//check isClose first to avoid isAncestor
	 			cout<<"\t*";
	 		cout<<endl;
	 		}
	 }
}

int isClose(int i,int j,int T)
{
return abs(i-j)<=T?1:0;
}

int isAncestor(int p,int c,int L,int **tr)
{
for(int i=0;i<L;i++) {
	if (  (tr[i][0]==p&&tr[i][1]==c)  ||  (tr[i][0]==p&&isAncestor(tr[i][1],c,L,tr))  )	
	//if (  (tr[i][0]==p&&tr[i][1]==c)  ||  (tr[i][1]==c&&isAncestor(p,tr[0][1],L,tr))  )	//won't work if I check the parent. ?
		{
		//cout<<endl<<p<<"->"<<c<<endl;
		return 1;
		}
	}
	return 0;
}
