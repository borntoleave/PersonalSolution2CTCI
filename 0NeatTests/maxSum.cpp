#include<iostream>
#include<iomanip>
#include<ctime>
#define N 5
using namespace std;
int regionSum(int **mat,int x,int y,int xl,int yl){
 int sum=0;
 for(int i=x;i<=xl;i++)
 	for(int j=y;j<=yl;j++)
 		sum+=mat[i][j];
 return sum;
}

int * traverse(int **mat,int *config,int *max){
 for(int i=0;i<N;i++)
 	for(int j=0;j<N;j++)
 		for(int il=i;il<N;il++)
 			for(int jl=j;jl<N;jl++){
 				//cout<<i<<' '<<j<<' '<<il<<' '<<jl<<endl;
 				int local=regionSum(mat,i,j,il,jl);
 				if(local>*max){
 					*max=local;
 					config[0]=i;
 					config[1]=j;
 					config[2]=il;
 					config[3]=jl;
 					}
 				}
 return config;
}

int main() {
 srand(time(NULL));
 int **mat=new int *[N];
 for(int i=0;i<N;i++){
 	mat[i]=new int[N];
	for(int j=0;j<N;j++)
		mat[i][j]=rand()%100-50;
	}
 for(int i=0;i<N;i++){
	for(int j=0;j<N;j++)
	 	cout<<right<<setw(4)<<mat[i][j];		
	cout<<endl;
	}
 cout<<"-----------------------------------"<<endl;
 int *config=new int [4],maxSum=-10000;
 config=traverse(mat,config,&maxSum);

 cout<<"max sum is "<<maxSum<<" for submatrix (("<<config[0]<<","<<config[1]<<"),("<<config[2]<<","<<config[3]<<"))"<<endl;
 for(int i=config[0];i<=config[2];i++){ 	
 	for(int j=config[1];j<=config[3];j++)
 		cout<<right<<setw(4)<<mat[i][j];
 	cout<<endl;
 	} 
}
