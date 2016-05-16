#include<iostream>
#include<ctime>
#define N 10
using namespace std;
void mergeS(int * a,int beg,int end);

int main(int argc,char *argv[])
{
 	if(argc!= 1 ){cerr<<"Format: "<<argv[0]<<" < > "<<endl;exit(-1);}
	srand(time(NULL));
 	clock_t start=clock();
	int *a=new int[N]();
	for(int i=0;i<N;i++){
		a[i]=rand()%N-N/2;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	mergeS(a,0,N-1);
	for(int i=0;i<N;i++)
		cout<<a[i]<<" ";
	cout<<endl;
 	cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	return 0;
 	
 	delete [] a;
}

void mergeS(int * a,int beg,int end){
		for(int i=0;i<N;i++)
		cout<<a[i]<<" ";
		cout<<endl;
	//cout<<beg<<" "<<end<<endl;
	if(beg>=end)return;
	int mid=beg+(end-beg)/2;
	mergeS(a,beg,mid);
	mergeS(a,mid+1,end);
	int *sorted=new int[end-beg+1](),cur=beg,p1=beg,p2=mid+1;
	while(p1<=mid&&p2<=end){
		cout<<p1<<" "<<p2<<endl;
		sorted[cur++]=a[p1]<a[p2]?a[p1++]:a[p2++];
		}
	while(p1<=mid)
		sorted[cur++]=a[p1++];
	while(p2<=end)
		sorted[cur++]=a[p2++];
	for(int i=beg;i<=end;i++)
		a[i]=sorted[i];
	//delete[] sorted;

}
