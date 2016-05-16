//RzL, Nov 6, 2015
//breadth first search
//	g++ islands2.cpp -o islands2
//	./islands2 case4.txt
#include<iostream>
#include<fstream>
#include<cmath>
#define PI 3.1415926
using namespace std;
void print(int **map,int dim);
int count(int **map,int dim);

class stack
{
public:
	int **stk;
	int currentPos;
	stack(int n){
		stk=new int *[n];
		for (int i=0;i<n;i++)	{
			stk[i]=new int[2];
			stk[i][0]=stk[i][1]=-1;
			}
		currentPos=-1;
		}
	~stack(){}
	int * pop() {
		int *currentIdx=new int[2];
		currentIdx[0]=stk[currentPos][0];
		currentIdx[1]=stk[currentPos][1];
		currentPos--;
		return currentIdx;
		}
	void push(int i,int j)	{
		currentPos++;
		stk[currentPos][0]=i;
		stk[currentPos][1]=j;
		}
};

int main(int argc, char * argv[])
{
if (argc!=2){cerr<<"Format: "<<argv[0]<<" <mapfile>"<<endl;exit(-1);}
ifstream in(argv[1],ios::in);
if (in.fail()){cerr<<"Cannot open file!"<<endl;exit(-2);}
int answer,dim;
in>>dim>>answer;
cout<<endl<<"dim: "<<dim<<'\t'<<"answer should be: "<<answer<<endl<<endl;
int **map=new int *[dim];
for(int i=0;i<dim;i++)	{
	map[i]=new int[dim];
	for(int j=0;j<dim;j++)	{
		map[i][j]=0;
		in>>map[i][j];
		}
	}
cout<<"initial map:---------- "<<endl;
print(map,dim);
cout<<"iterations:----------"<<endl;
int nIsland=count(map,dim);
cout<<nIsland<<" islands found!(Indexes shifted by 1)"<<endl<<endl;
for(int i=0;i<dim;i++)	//clean up
	delete [] map[i];
delete [] map;
}

void print(int **map,int dim)
{
int ones=0;
for(int i=0;i<dim;i++)	{
	for(int j=0;j<dim;j++)	{
		if(map[i][j]) {
			cout<<map[i][j]<<' ';
			}
		else
			cout<<"  ";			
		}
	cout<<endl;
	}
cout<<endl;
}	

int count(int **map,int dim)
{
int currentGroup=2;//shift the group indexes by 1.
for(int i=0;i<dim;i++)
	for(int j=0;j<dim;j++) 
		if(map[i][j]==1)	{
			stack s(dim*dim);
			s.push(i,j);
			//cout<<s.currentPos<<endl;
			while(s.currentPos>=0)	{//stack is not empty
				int *currentIdx=new int[2];
				currentIdx=s.pop();
				//cout<<s.currentPos<<endl;
				if(map[currentIdx[0]][currentIdx[1]]==1) {
					map[currentIdx[0]][currentIdx[1]]=currentGroup;
					for(double theta=0;theta<4;theta++)	{//loop the four directions
						int i_incr=round(sin((theta+1)*PI/2));
						int j_incr=round(cos((theta+1)*PI/2));
						int newi=currentIdx[0]+i_incr;
						int newj=currentIdx[1]+j_incr;
						if(	   newi>=0&&newi<dim
							&& newj>=0&&newj<dim //boundary conditions
							&& map[newi][newj]&&map[newi][newj]!=currentGroup) {
								s.push(newi,newj);
								}	
						}
					}
				}
			currentGroup++;
			print(map,dim);
			}
return currentGroup-2;
}

