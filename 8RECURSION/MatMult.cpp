#include<iostream>
#include<ctime>
using namespace std;
int **table;

int find(int * arr, int beg,int end){
	if(end-beg<2)return 0;
	//if(end-beg==2)return arr[beg]*arr[beg+1]*arr[end];
	int min=100000,local;
	for(int sep=beg+1;sep<end;sep++){
		local=find(arr,beg,sep)+find(arr,sep,end)+arr[beg]*arr[sep]*arr[end];
		min=local<min?local:min;
	}
	return min;
}

int opt(int * arr, int beg,int end){
	if(end-beg<2)return 0;
	//if(end-beg==2)return arr[beg]*arr[beg+1]*arr[end];
	if(table[beg][end])return table[beg][end];
	int min=100000,local;
	for(int sep=beg+1;sep<end;sep++){
		local=opt(arr,beg,sep)+opt(arr,sep,end)+arr[beg]*arr[sep]*arr[end];
		min=local<min?local:min;
	}
	table[beg][end]=min;
	return min;
}



int main(int argc,char *argv[])
{
 	if(argc!= 2 ){cerr<<"Format: "<<argv[0]<<" < num of matrix > "<<endl;exit(-1);}
	srand(time(NULL));
 	clock_t start=clock();
    int n=atoi(argv[1]);
	table=new int*[n];
	for (int i=0;i<5;i++)
		table[i]=new int[n]();
	int *arr=new int[atoi(argv[1])];
	for(int i=0;i<n;i++){
		arr[i]=rand()%20;
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<find(arr,0,4)<<endl;
	cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
	
	start=clock();
	cout<<opt(arr,0,4)<<endl;
 	cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	return 0;
}
