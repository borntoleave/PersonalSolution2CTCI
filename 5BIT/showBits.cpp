#include<iostream>
#include<ctime>
using namespace std;
union num{
    bool b[sizeof(int)*8];
    int d;
    
    num(int n):d(n){
        cout<<"Dec: "<<d<<endl<<sizeof(bool)//no bool takes 8 bits. you can't show the bit representation.
            <<"Bin: ";
        for(int i=0;i<sizeof(int)*8;i++)
            cout<<b[i];
        cout<<endl;
    }
    ~num(){}
    
};

int main(int argc,char *argv[])
{
 	if(argc!= 2 ){cerr<<"Format: "<<argv[0]<<" < decimal number > "<<endl;exit(-1);}
    int x=atoi(argv[1]);
	srand(time(NULL));
 	clock_t start=clock();
    num n(x);
    

 	cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	return 0;
}
