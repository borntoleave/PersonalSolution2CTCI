#include<iostream>
#include<ctime>
#include<cmath>
#include<iomanip>
#include<utility>
#include<stack>
#define LARGE 1000
using namespace std;

void print(int **grid,int m,int n){
	for(int i=0;i<2*n+3;i++)
		cout<<'_';
	cout<<endl;
	for(int i=0;i<m;i++){
		cout<<"| ";
		for(int j=0;j<n;j++)
			cout<<(	grid[i][j]==0?	'#':
					grid[i][j]==-1?	'.':' ')<<' ';
		cout<<"|";
		cout<<endl;
	}
	for(int i=0;i<2*n+3;i++)
		cout<<'-';
	cout<<endl;
}


void FloydWarshall(int **grid,int m,int n){//uncomplished
	int **map=new int *[m*n];
	int r1,c1,r2,c2;
	for(int i=0;i<m*n;i++){
		map[i]=new int [m*n]();
		for(int j=0;j<m*n;j++){
			r1=i/n;
			c1=i%n;
			r2=j/n;
			c2=j%n;
		if(abs(r1-r2)+abs(c1-c2)<2)
			map[i][j]=1;
		}
	}
	print(map,m*n,m*n);
}

void init(int **&grid,int m,int n){
	int ratio=1;
	srand(time(NULL));
	grid=new int * [m];
	for(int i=0;i<m;i++){
		grid[i]=new int[n];
		for(int j=0;j<n;j++){
			grid[i][j]=rand()%10;
			grid[i][j]=grid[i][j]>ratio?1:0;
		}
	}
	grid[0][0]=grid[m-1][n-1]=1;
}

void copy(int **&a1,int **a2,int m,int n){
	a1=new int * [m];
	for(int i=0;i<m;i++){
		a1[i]=new int[n];
		for(int j=0;j<n;j++)
			a1[i][j]=a2[i][j];
	}
}


int findPath(int **grid,int m,int n,int i,int j){
	if(i<0||j<0||i>=m||j>=n||grid[i][j]!=1)
		return 0;
	//cout<<i<<'\t'<<j<<endl;
	grid[i][j]=-1;
	if(i==m-1&&j==n-1){
		return 1;
		}
	if(	  findPath(grid,m,n,i+1,j+1)
		||findPath(grid,m,n,i+1,j)
		||findPath(grid,m,n,i,j+1)
		||findPath(grid,m,n,i,j-1)
		||findPath(grid,m,n,i-1,j))	{
		grid[i][j]=-1;
		return 1;
	}
	else {
		grid[i][j]=-2;
		return 0;
		}
}

int findMinPath(int **grid,int m,int n,int i,int j){//works for dim<=5;
	if(i<0||j<0||i>=m||j>=n||grid[i][j]!=1){	
		return LARGE;}
	//cout<<i<<'\t'<<j<<endl;
	grid[i][j]=-1;
	if(i==m-1&&j==n-1){
		return 1;
		}

	int itr[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
	int min=LARGE,min_itr[2]={1,0};
	int lc[4];
		int **temp;
	for(int it=0;it<4;it++){
		copy(temp,grid,m,n);
		int local=findMinPath(temp,m,n,i+itr[it][0],j+itr[it][1]);
		delete []temp;
		lc[it]=local;
		if(local<min){
			min=local;
			min_itr[0]=itr[it][0];
			min_itr[1]=itr[it][1];
		}
	}
	//cout<<i<<","<<j<<": ";
	//for(int l=0;l<4;l++)
	//	cout<<setw(5)<<lc[l];
	//cout<<"\t"<<min<<endl;
	//cout<<min;
	if(min<LARGE){
		findMinPath(grid,m,n,i+min_itr[0],j+min_itr[1]);
		
		return min+1;
		}
	else {
		grid[i][j]=-2;
		return LARGE;
		}
}
	
int main(int argc,char * argv[]){
	if(argc!=3){
		cerr<<"Format: "<<argv[0]<<" <m> <n>"<<endl;
		exit(-1);}
	int m=atoi(argv[1]),n=atoi(argv[2]);
	int **grid,**fw;
	init(grid,m,n);
	copy(fw,grid,m,n);
	print(grid,m,n);
	cout<<"There is "<<(findPath(grid,m,n,0,0)?"a ":"no ")<<"path."<<endl;
	print(grid,m,n);
	//FloydWarshall(fw,m,n);
	//print(fw,m,n);
	//cout<<findMinPath(fw,m,n,0,0)<<endl;
	//print(fw,m,n);
}
