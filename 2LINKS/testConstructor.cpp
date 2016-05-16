#include<iostream>
#include<ctime>
using namespace std;

class obj{
public:
    int x;
    int y[2];
    obj(int d){x=d;cout<<x<<"call"<<endl;}
    ~obj(){cout<<x<<"clean"<<endl;}
};

void fun(obj o){
    cout<<o.x<<"fun"<<endl;
    o.x=2;
}

int main(int argc,char *argv[])
{
 	if(argc!= 1 ){cerr<<"Format: "<<argv[0]<<" < > "<<endl;exit(-1);}
	srand(time(NULL));
 	clock_t start=clock();
    
    obj *s=new obj(3);
    
    obj o(13);
    
    obj b(o);
    b.x=0;
    
    cout<<"seperate"<<endl;
    fun(o);


 	cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;

    delete s;
    
 	return 0;
}
