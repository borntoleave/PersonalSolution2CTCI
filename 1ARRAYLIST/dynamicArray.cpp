//recRead() recursively reads in a data file and dynamically allocate an array to store them within one scan.
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void recRead(ifstream &in,int *&arr,int &n){
	int buffer;
	if(!(in>>buffer)){
		arr=new int[n+1];
		arr[0]=n;
		return;
	}
	n++;
	recRead(in,arr,n);
	arr[n--]=buffer;
}

int main(int argc,char *argv[])
{
 if(argc!= 2 ){
 	cerr<<"Format: "<<argv[0]<<" < filename > "<<endl;
 	exit(-1);}
 ifstream in(argv[1],ios::in);
 int buffer;
 int n=0,size;
 int *arr;
 recRead(in,arr,n);
 size=arr[0];
 cout<<"input size = "<<size<<endl;
 for(int j=1;j<=size;j++)
 	cout<<arr[j]<<' ';
 cout<<endl;
}



