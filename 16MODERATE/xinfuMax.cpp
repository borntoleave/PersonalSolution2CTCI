#include<iostream>
//#include<bitset>
using namespace std;

void Max(int a, int b){
 int arr[2]={a,b};
 cout << arr[(((a-b)>>31)&1)] << endl;
}

int main(int argc, char *argv[]){
	int a=atoi(argv[1]),b=atoi(argv[2]);
 Max(a,b);
 return 0;
}
