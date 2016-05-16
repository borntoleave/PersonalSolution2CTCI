#include<iostream>
#include<iomanip>
using namespace std;
int totalT=0;
void sort(int *psg,int n);
void passOrder(int *psg,int n);
int main(int argc, char *argv[])
{
 if (argc<3){cerr<<"Format: "<<argv[0]<<" <sequence(n>=2) of numbers>"<<endl;exit(-1);}
 int *psg=new int [argc-1];
 for (int i=0;i<argc-1;i++)
	psg[i]=atoi(argv[1+i]);
 sort(psg,argc-1);
 for (int i=0;i<argc-1;i++)
 	cout<<psg[i]<<' ';
 cout<<endl;
 passOrder(psg,argc-1);
 cout<<"The shortest time to pass is "<<totalT<<endl;
}

void sort(int *psg,int n)
{
 for(int i=0;i<n;i++)
 	for(int j=i+1;j<n;j++)
 		if(psg[i]>psg[j]){
 			psg[i]^=psg[j];
 			psg[j]^=psg[i];
 			psg[i]^=psg[j];
 			}
}

void passOrder(int *psg,int n)
{
 totalT+=psg[1];//two mins ->
 cout<<setw(2)<<psg[0]<<","<<setw(2)<<psg[1]<<" => \ttotaltime "<<totalT<<endl;
 if(n<=2) {cout<<"done! \ttotaltime "<<totalT<<endl;return;}
 totalT+=psg[0];//min1  <-
 cout<<setw(5)<<psg[0]<<" <= \ttotaltime "<<totalT<<endl;
 totalT+=psg[n-1];//two maxs ->
 cout<<setw(2)<<psg[n-2]<<","<<setw(2)<<psg[n-1]<<" => \ttotaltime "<<totalT<<endl;
 totalT+=psg[1];//min2  <-
 cout<<setw(5)<<psg[1]<<" <= \ttotaltime "<<totalT<<endl;
 passOrder(psg,n-2);
}

