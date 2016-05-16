#include<iostream>
#include<ctime>
using namespace std;

template<class T>
T max(T &a,T &b){
    return a>b?a:b;
}

int main(int argc,char *argv[])
{
 	if(argc!= 1 ){cerr<<"Format: "<<argv[0]<<" < > "<<endl;exit(-1);}
	srand(time(NULL));
 	clock_t start=clock();
    
    cout<<max(1,2)<<endl
        <<max(3.1,3.4)<<endl
        <<max("hello","world")<<endl;


 	cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	return 0;
}
