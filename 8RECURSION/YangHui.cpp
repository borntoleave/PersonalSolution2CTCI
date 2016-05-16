#include<iostream>
#include<ctime>
#include<iomanip>
using namespace std;
void yang(int k){
    int *line=new int[k+1](),*lineLag=new int[k+1]();
    for(int l=0;l<k;l++){
        if(!l){
            lineLag[0]=1;
            lineLag[1]=1;}
        else{

        for(int i=1;i<l+2;i++)
            line[i]=lineLag[i-1]+lineLag[i];
        for(int i=1;i<l+2;i++)
            lineLag[i]=line[i];
        }
        for(int i=0;i<(k-l);i++)
            cout<<"   ";
        for(int i=0;i<l+2;i++)
            cout<<setw(3)<<lineLag[i]<<"   ";
        cout<<endl;
    }
}

int main(int argc,char *argv[])
{
 	if(argc!= 2 ){cerr<<"Format: "<<argv[0]<<" < k > "<<endl;exit(-1);}
    int k=atoi(argv[1]);
	srand(time(NULL));
 	clock_t start=clock();
    
    yang(k);


 	cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	return 0;
}
