#include<iostream>
#include<ctime>
using namespace std;
class cl{
	public:
		int idx;
		int *p;
		cl(int n):idx(n),p(new int [n]){
			for(int i=0;i<n;i++)
				p[i]=i*i;
		}
};

int main(int argc,char *argv[])
{
 	if(argc!= 1 ){cerr<<"Format: "<<argv[0]<<" < > "<<endl;exit(-1);}
	srand(time(NULL));
 	clock_t start=clock();
	cl a(10);
	cl ** arr=new cl* [6];
	for(int i=1;i<6;i++){
		arr[i]=new cl(i);
		cout<<arr[i]->idx<<" "<<arr[i]->p[i-1]<<endl;
		}
 	cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	return 0;
}
