//
#include<iostream>
using namespace std;
int visit=0,num;
int *seq;
void rec(int n);
int main(int argc,char *argv[])
{
	if(argc<2)	{
		cerr<<argv[0]<<" <num of dices>"<<endl;
		exit(-1);
	}
	num=atoi(argv[1]);
	seq=new int [num];
	rec(num);
	cout<<visit<<endl;
}

void rec(int n)
{
	if(n<1)	{
		visit++;
		for(int i=0;i<num;i++)
			cout <<seq[i];
		cout<<'\t';
		return;
	}
	
	for(int i=1;i<=6;i++)	{
		seq[num-n]=i;
		rec(n-1); 
	}
	cout <<endl;

}
