#include<iostream>
#include<ctime>
using namespace std;
void sort(int *arr,int beg,int end){
    if(beg>=end)
        return;
    int mid=(beg+end)/2;
    sort(arr,beg,mid);
    sort(arr,mid+1,end);
    int l=beg,r=mid+1,cur=0,*sorted=new int [end-beg+1];
    while(l<=mid&&r<=end){
        sorted[cur++]=arr[l]<arr[r]?arr[l++]:arr[r++];
    }
    while(l<=mid)
        sorted[cur++]=arr[l++];
    while(r<=end)
        sorted[cur++]=arr[r++];
    for(int i=0;i<end-beg+1;i++)
        arr[beg+i]=sorted[i];
}


int main(int argc,char *argv[])
{
 	if(argc!= 1 ){cerr<<"Format: "<<argv[0]<<" < > "<<endl;exit(-1);}
	srand(time(NULL));
 	clock_t start=clock();
    int unsorted[13]={1,2,4,7,10,11,7,12,6,7,16,18,19};
    int arr[13]={1,2,4,7,10,11,7,12,6,7,16,18,19};
    sort(arr,0,12);
    for(int i=0;i<13;i++)
        cout<<unsorted[i]<<" ";
    cout<<endl;
    for(int i=0;i<13;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    for(int i=0;i<13;i++)
        if(unsorted[i]!=arr[i]){
            cout<<i<<" ";
            break;
        }
    for(int i=12;i>=0;i--)
        if(unsorted[i]!=arr[i]){
            cout<<i<<" ";
            break;
        }
    cout<<endl;
 	cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	return 0;
}
