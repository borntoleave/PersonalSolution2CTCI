#include<iostream>
#include<ctime>
using namespace std;

union num{
float d;
int n[sizeof(float)/sizeof(int)];
num(float d):d(d){}
};

void printBit(float d){
num y(-1);

	for(int i=0;i<sizeof(float)/sizeof(int);i++){
		for(int j=sizeof(int)*8-1;j>=0;j--){
			cout<<((y.n[i]&(1<<j))>0?1:0);
			}
			cout<<" ";}
		cout<<endl;
}

int countBits(int x){
	x=((~x)^x);
	int c=0;
	while(x<0){
		x=x^(1<<c);
		c++;
	}
	return c;
}

int countBits2(int x){
	x=((~x)^x);
	int c=0;
	while(x){
		x=x&(x-1);
		c++;}
		cout<<c<<endl;
		return c;

}

int countBits3()
{
	int n=1;
	int b=1;
	while(n>0){
		n<<=1;
		b++;
	}
	cout<<n<<endl;
	return b;
}

int main(int argc,char *argv[])
{
 	if(argc!= 2 ){cerr<<"Format: "<<argv[0]<<" < num > "<<endl;exit(-1);}
	srand(time(NULL));
 	clock_t start=clock();
	int x=atoi(argv[1]);
	cout <<countBits(x)<<endl;
	cout<<sizeof(double)<<" "<<sizeof(int)<<" "<<sizeof(double)/sizeof(int)<<endl;
	printBit(-1);
	printBit(1);

	cout<<countBits2(3)<<endl;
	cout<<countBits3()<<endl;

 	cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	return 0;
}
