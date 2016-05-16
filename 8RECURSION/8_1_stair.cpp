#include<iostream>
#include<ctime>
using namespace std;

long noOfSteps(int n, long arr[]){//key from the website
	if(arr[n])
		return arr[n];
	if(n<4){
		if(n==1)
			arr[n] = 1;
		else if(n==2){
			arr[2] = 2;
		}
		else if(n==3){
			arr[3] = 4;
		}
	}
	else
		arr[n] = noOfSteps(n-1, arr) + noOfSteps(n-2, arr) + noOfSteps(n-3, arr);
	return arr[n];
}

void recursive(int left,long *count){
	if(left<2)
		return;
	for(int s=1;s<=3&&s<=left;s++){
		if(!count[left-s])
			recursive(left-s,count);
		count[left]+=count[left-s];
	}
		
}

void stupid(int left,long &ct){
	if(!left){
		ct++;
		return;
	}
	for(int s=1;s<=3&&s<=left;s++)
		stupid(left-s,ct);
}

void iterative(int n,long *count){
	for(int i=2;i<=n;i++)
		for(int s=1;s<=3&&s<=i;s++)
			count[i]+=count[i-s];
}

int main(){
	int n=100;
	clock_t start;

//	start=clock();
//	long ct=0;
//	stupid(n,ct);//takes too long time for large n > 30
//	cout<<"Stupid:\t\t"<<ct<<'\t'<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;

	start=clock();
	long *count2=new long[n+1]();
	count2[0]=1;
	count2[1]=1;
	iterative(n,count2);
	//for(int i=1;i<=n;i++)
	//cout<<count2[i]<<' ';
	cout<<"Iterative:\t"<<count2[n]<<'\t'<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;

	start=clock();
	long *count=new long[n+1]();
	count[0]=1;
	count[1]=1;
	recursive(n,count);
	//for(int i=1;i<=n;i++)
	//cout<<count[i]<<' ';
	cout<<"Recursive:\t"<<count[n]<<'\t'<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;

	start=clock();
	long *arr=new long[n+1]();
	cout<<"Solution:\t"<<noOfSteps(n, arr)<<'\t'<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;

}
