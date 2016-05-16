#include<iostream>
using namespace std;
int main(int argc, char *argv[])
{
 if (argc!=4){
 	cerr<<"Format: "<<argv[0]<<" <n1> <n2> <precision>"<<endl;
 	exit(-1);
 	}
 double n1,n2,prec;
 n1=atof(argv[1]);
 n2=atof(argv[2]);
 prec=atof(argv[3]);
 double t=0,nt=n1,p=1;
 cout<<"Normal method:\t"<<n1<<" / "<<n2<<" = "<<n1/n2<<endl;
 while (p>prec&&nt){
    while(nt>n2) {
		nt-=n2;
		t+=p;
 	}
 	nt*=10;
 	p*=0.1;
 	}
 cout<<"My method:\t"<<n1<<" / "<<n2<<" = "<<t<<endl;
}

