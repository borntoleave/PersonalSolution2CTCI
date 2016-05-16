#include<iostream>
#include<cmath>
using namespace std;
int binarysearch(int *arr,int length,int num)	//logN
{
 int startIdx=0;
 int endIdx=length-1;
 while (startIdx<=endIdx) {
	int midIdx=(startIdx+endIdx)/2;
	if (arr[midIdx]>num)
		endIdx=midIdx-1;
	else if (arr[midIdx]<num)
		startIdx=midIdx+1;
	else if (arr[midIdx]==num)
		return midIdx;		
 	}
 return -1;
}

int recursive(int *arr,int start,int end,int num)
{
 if (start>end)
	return -1;
 int mid = (start+end)/2;
 if (arr[mid]<num)
 	return recursive(arr,mid+1,end,num);
 else if (arr[mid]>num)
	return recursive(arr,start,mid-1,num);
 else 
 	return mid;

}

int origSearch(int *arr,int length)	//logN
{
 int startIdx=0;
 int endIdx=length-1;
 while (startIdx<= endIdx) {
 	int mid = (startIdx+endIdx)/2;
    if (mid == 0 or arr[mid] < arr[mid-1])
    		return mid;
    if (arr[mid] > arr[0])
        startIdx = mid + 1;
    else
        endIdx = mid - 1;
    }
   	return 0;
}

int main(int argc, char *argv[])
{
 int arr[]		= {2, 4, 5, 8,9,10,11, 12, 17};
 int shiftArr[]	= {11, 12, 17, 2, 4, 5,8,9,10};//{9, 12, 17, 2, 4, 5};
 int num=atoi(argv[1]);
 int length=sizeof(shiftArr)/sizeof(int);
 int origIdx=origSearch(shiftArr,length);
 cout<<"looking for "<<num<<" in shifted array."<<endl;
 cout<<"Array shifted by "<<origIdx<<endl;
 int result;
 if(num<shiftArr[0]) {
 	result=binarysearch(shiftArr+origIdx,length-origIdx,num);
 	if (result>=0)
 		result+=origIdx;
 	}
 else 
 	result=binarysearch(shiftArr,origIdx,num);
 cout <<result<<endl;
 cout<<recursive(arr,0,length,num)<<endl;
}


