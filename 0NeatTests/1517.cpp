#include<iostream>
#include<ctime>
#include<cmath>
#define RUN 10000000
using namespace std;
double stdd(int *count,int n)
{
double mean,std;
mean=std=0;
for(int i=1;i<=n;i++)
	mean+=count[i];
	mean/=n;
for(int i=1;i<=n;i++)
	std+=((count[i]-mean)*(count[i]-mean));	
	return sqrt(std)/(1.0*RUN/7);
}

int rand_15()//random 1-5
{
 return rand()%5+1;
}

int rand_17a()//change to your function. RzLi
{
 int r=0;
 while(r==0)	{
 int digit[3]={5,5,5};
 for(int i=0;i<3;i++){
	while(digit[i]>4)
		digit[i]=rand_15();
	digit[i]%=2;
	}
 r=4*digit[0]+2*digit[1]+digit[2];
 }
 return r;
}

int rand_17b() //Best
{
 while(1){
	int num=5*(rand_15()-1)+rand_15();
	if(num<22) return num%7+1;
	}
}

int rand_17(){ //Xinfu Lv
	while(1){	
		int x=10*rand_15()+rand_15();
		if(x==11) return 1;
		if(x==22) return 2;
		if(x==33) return 3;
		if(x==44) return 4;
		if(x==55) return 5;
		if(x==51) return 6;
		if(x==42) return 7;
	}
}

void test(int n)
{
 srand (time(NULL));
 clock_t start=clock();
 int *count=new int[n+1];
 for(int i=0;i<=n;i++)
 	count[i]=0;
 for(int i=0;i<RUN;i++)
 	if(n==5)
		count[rand_15()]++;		
	else 
		count[rand_17()]++;
 cout<<endl
 	<<"* time for generating "<<RUN<<" [1~"<<n<<"] is "<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 for(int i=1;i<=n;i++)
 	cout<<count[i]<<'\t';
 cout<<endl
 	<<"standard deviation "<<stdd(count,n)<<endl
 	<<"------------------"<<endl;
}

int main()
{
 test(5);
 test(7);
}
