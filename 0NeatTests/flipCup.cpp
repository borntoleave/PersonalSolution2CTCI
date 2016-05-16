#include<iostream>
#include<ctime>
#include<cmath>
#define TRY 1000
using namespace std;
int main(int argc,char *argv[])
{
 if(argc!= 1 ){
 	cerr<<"Format: "<<argv[0]<<" < > "<<endl;exit(-1);}
 int cup;
 int idx;
 double visit=0;
 srand(time(NULL));
 for(int N=10;N<100;N+=10){//N people
 	visit=0;
 	int *mem=new int[N];
 	for(int exper=0;exper<TRY;exper++){//TRY experiments
 		for(int i=0;i<N;i++)
 			mem[i]=0;
 		cup=0;	
 		while(mem[0]<N-1){
 			visit++;
 			idx=rand()%N;
 			if(!mem[idx]&&idx&&cup)//idx!=0&&cup==1 up && haven't done it
 				cup=0;
 			else if(!idx&&!cup){//idx==0&&cup==0 down
 				cup=1;
 				mem[0]++;
 				}	
			}
 		}
	cerr<<N<<" men's Averagy is "
		<<visit/TRY<<" \t( "
		<<sqrt(abs(N*(N+1)-visit/TRY))/N<<'\t'
		<<sqrt(abs(N*N-visit/TRY))/N<<'\t'
		<<sqrt(abs((N+1)*(N-1)-visit/TRY))/N<<" )"<<endl;
	}
	cout<<"\t\t\t\tNxN+1\t\tNxN\t\tN^2-1"<<endl;
 return 0;
}

