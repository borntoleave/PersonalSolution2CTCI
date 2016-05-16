//get max without using compare or if.
#include<iostream>
#include<ctime>
#include<cmath>
using namespace std;
int max(int a,int b){
	int dif=a-b;
	int signA=((a>>31)&1)^1,signB=((b>>31)&1)^1,signAB=((dif>>31)&1)^1;//1 for neg,0 for pos
	cout<<signA<<" "<<signB<<" "<<signAB<<endl;
    int use_sA=signA^signB,use_sAB=use_sA^1;
    int use=signA*use_sA+signAB*use_sAB;
    
	return a*(use)+b*(use^1);//problem!
}

int algMax(int a,int b){//may overflow
    double aAb=a+b,a2b2=a*a+b*b;
    double xy2=aAb*aAb-a2b2,xMy=sqrt(a2b2-xy2);
    return (xMy+aAb)/2;
}



double errMax(double a,double b){//return max without if or >=<
    try {
        bool *arr=new bool [long(a-b-1)];
        delete [] arr;
        return a;
    } catch (bad_alloc) {
        return b;
    }
}

int main(int argc,char *argv[])
{
 	if(argc!= 3 ){cerr<<"Format: "<<argv[0]<<" < > "<<endl;exit(-1);}
 	double a=atof(argv[1]),b=atof(argv[2]);
	srand(time(NULL));
 	clock_t start=clock();
	
	//cout<<max(a,b)<<endl;
    
    cout<<algMax(a,b)<<endl;
    
    cout<<errMax(a,b)<<endl;
 	cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	return 0;
}
