/* 1 2 3 4 5  -> 1 iterative
1 to 2 
2 to 3 
3 to 4
4 to 1
5 to 2
// 5 1 2 3 4

// 1 2 3 4 5   -> 2 recursive
1 to 3
3 to 5
5 to 2
2 to 4
4 to 1

// 4 5 1 2 3
*/
#include<iostream>
#include<ctime>
int N;
using namespace std;
void print(int *arr){
	for(int i=0;i<N;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void swap(int &a,int &b){
	a^=b;
	b^=a;
	a^=b;
}
void rec(int *arr,int shift,int orig,int from,int to,int &hold){
	if(to==orig){
		cout <<from<<" -> "<<to<<endl;
		swap(arr[from],arr[to]);
		hold=0;}
	if(hold){
		cout <<from<<" -> "<<to<<endl;
		rec(arr,shift,orig,to,(to+shift)%N,hold);}
	swap(arr[from],arr[to]);
}
void recWrap(int *arr,int shift,int from,int to){
	cout<<"Recursively shift by "<<shift<<endl;
	int hold=1;
	if(N%shift==0){
		for(int i=0;i<shift;i++){
			hold=1;
			rec(arr,shift,i,i,i+shift,hold);
		}
	}	
	else rec(arr,shift,0,from,to,hold);
}



void rotate(int *arr, int shift){
	cout<<"Iteratively shift by "<<shift<<endl;
	int *idx=new int[N];

	for(int i=0;i<N;i++)
		cout<<arr[(N+i-shift)%N]<<" ";
	cout<<endl;	
}

int main(int argc,char *argv[])
{
 	if(argc!= 3 ){cerr<<"Format: "<<argv[0]<<" <N> <shift> "<<endl;exit(-1);}
	int shift=atoi(argv[2]);
	N=atoi(argv[1]);
	srand(time(NULL));
 	clock_t start=clock();
	int *arr=new int[N];
	for(int i=0;i<N;i++)
		arr[i]=i+1;//rand()%10;
	print(arr);
	rotate(arr,3);
	rotate(arr,4);
	cout<<endl;
	print(arr);
	rotate(arr,shift);
	recWrap(arr,shift,0,shift);
	print(arr);
 	cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	return 0;
}
