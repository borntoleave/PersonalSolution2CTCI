#include<iostream>
#include<ctime>
using namespace std;
void swap(int &a,int &b){
	if(a==b)
		return;
	a^=b;
	b^=a;
	a^=b;
}
void sort(int *&arr,int beg,int end){
	if(beg>=end)
		return;
	int left=beg,right=end;
	while(left+1<=right)	{
		if(arr[left]>arr[left+1])
			swap(arr[left+1],arr[left++]);
		else
			swap(arr[right--],arr[left+1]);
	}
	sort(arr,beg,left-1);
	sort(arr,left+1,end);
}

int main(int argc,char *argv[])
{
 	if(argc!= 2 ){cerr<<"Format: "<<argv[0]<<" < N > "<<endl;exit(-1);}
	srand(time(NULL));
 	clock_t start=clock();
	int N=atoi(argv[1]);
	int *arr=new int [N];
	for(int i=0;i<N;i++){
		arr[i]=rand()%(3*N)-N;
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	sort(arr,0,N-1);

	for(int i=0;i<N;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	

 	cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	return 0;
}
