#include<iostream>
#include<ctime>
#include<vector>
#include<iomanip>
using namespace std;
int max(int a,int b){
return a>b?a:b;
}

int find(int * arr,int begin,int end){
	if(end<begin)
		return -1;
	int mid=begin+(end-begin)/2;
	if(arr[mid]==mid)
		return mid;
	if(arr[mid]>mid){
	return max(
		find(arr,begin,mid-1),
		find(arr,arr[mid],end));}
	else {
	return max(
		find(arr,begin,arr[mid]),
		find(arr,mid+1,end));
		}
}
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
//a^=b;
//b^=a;
//a^=b;
}

void bSort(vector<int> &arr){
	int dim=arr.size();
	for(int i=0;i<dim;i++)
		for(int j=i+1;j<dim;j++)
			if(arr[i]>arr[j])
				swap(arr[i],arr[j]);
}

void sort(int *arr,int begin,int end){
	if(begin>=end)
		return;
	for(int i=0;i<10;i++){
		if(i==begin)
			cout<<"<";
		else cout<<' ';
		cout<<setw(2)<<arr[i];
		if(i==end)
			cout<<">";
		else cout<<' ';
		}
	cout<<endl;

	int v=arr[begin],l=begin,r=end,c=begin+1;
	while(c<=r){
		if(arr[c]<v&&c<=r)
			swap(arr[l++],arr[c++]);		
		else if(arr[c]>=v&&c<=r)
			swap(arr[r--],arr[c]);
		}
	arr[l]=v;
	sort(arr,begin,l-1);
	sort(arr,l+1,end);
}


int main(){
	srand(time(NULL));
	int dim=10;
	int * arr=new int[10];
	for(int i=0;i<dim;i++)
		arr[i]=rand()%16;
	sort(arr,0,9);
	//bSort(arr);
	for(int i=0;i<dim;i++){
		if(arr[i]==i)
			cout<<"*";
		cout<<arr[i]<<" ";
	}
	
	cout<<endl;
	cout<<find(arr,0,dim-1)<<endl;
}
