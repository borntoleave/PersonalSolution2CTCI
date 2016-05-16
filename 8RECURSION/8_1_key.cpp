#include <iostream>
using namespace std;

int noOfSteps(int n, long arr[]){
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

int main(){
	int n = 36;
	long *arr=new long[n+1];
	for(int i=1;i<=n;i++)
		arr[i] = 0;
	cout<<noOfSteps(n, arr)<<endl;
	return 0;
}
