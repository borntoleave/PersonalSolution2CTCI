#include<iostream>
#include<fstream>
#include<cmath>
using namespace std; 

class treeNode
{
private:
	int value;
	treeNode * parent;
	treeNode * childL;
	treeNode * childR;
public:
	treeNode(){
		value=0;
		parent=NULL;
		childL=NULL;
		childR=NULL;
		};
	treeNode(int v,treeNode * p,treeNode * c){
		value=v;
		parent=p;
		if(childL==NULL)
			childL=c;
		else
			childR=c;
		};
	int getV(){return value;}
	treeNode * getP(){return parent;}	
	treeNode * getL(){return childL;}
	treeNode * getR(){return childR;}
	void setV(int v){value=v;}
	void setP(treeNode * p){parent=p;}
	void setL(treeNode * l){childL=l;}
	void setR(treeNode * r){childR=r;}
};


int isClose( int i,int j,int T);
int isAncestor(int p,int c,int N,int **tr);

int main(int argc, char *argv[])
{
if(argc!=2)		{cerr<<"Format: "<<argv[0]<<" <input>"<<endl;exit(-1);}
ifstream f(argv[1],ios::in);
if (f.fail())	{cerr<<"Fail to open input file!"<<endl;exit(-2);}
int N,T;
f>>N>>T;

for(int l=0;l<N-1;l++)	{
		int p,c;
		f>>p>>c;
		treeNode *a=new treeNode();
		a.setV(p);
		
		treeNode *
		
	}
}

