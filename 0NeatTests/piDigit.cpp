#include<iostream>
#include<ctime>
#include<cmath>
using namespace std;
int main(int argc,char *argv[])
{
 	if(argc!= 1 ){cerr<<"Format: "<<argv[0]<<" < > "<<endl;exit(-1);}
	srand(time(NULL));
 	clock_t start=clock();
    //string p=to_string(M_E);
    //cout<<p<<endl;
    string s="hello";
    cout<<s+&to_string(M_PI)[2]<<endl;


 	cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	return 0;
}
