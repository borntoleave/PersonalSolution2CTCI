//RzL, Nov 6, 2015
//evolutionary solution. fail at case 4.
//	g++ islands.cpp -o islands
//	./islands case4.txt
#include<iostream>
#include<fstream>
#include<cmath>
#define PI 3.1415926
using namespace std;
int print(int **map,int dim);
int count(int **map,int dim);

int print(int **map,int dim)
{
int ones=0;
for(int i=0;i<dim;i++)	{
	for(int j=0;j<dim;j++)	{
		if(map[i][j]) {
			ones++;
			cout<<map[i][j]<<' ';
			}
		else
			cout<<"  ";
			
		}
	cout<<endl;
	}
	cout<<"Current ones: "<<ones<<endl<<endl;
	return ones;
}				

int count(int **map,int dim)
{
int ones;
for (int nb_range=1;nb_range<=2;nb_range++) 
	for(int nb_cut=1;nb_cut<=nb_range;nb_cut++){//first delete the 1s with 1 neighbor, then 2
		for(int i=0;i<dim;i++)			//time: O(dim^2), space: O(dim^2)
			for(int j=0;j<dim;j++) 
				if (map[i][j])	{
					int nb=0;
					for(double theta=0;theta<4;theta++)	{//loop the four directions
						int i_incr=round(sin((theta+1)*PI/2));
						int j_incr=round(cos((theta+1)*PI/2));
						if(	   i+i_incr>=0&&i+i_incr<dim
							&& j+j_incr>=0&&j+j_incr<dim //boundary condition
							&& map[i+i_incr][j+j_incr])	//none 0
							nb++;
						}
						if (nb>0&&nb<=nb_cut)
							map[i][j]=0;
					}
	ones=print(map,dim);
	}
return ones;
}

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
print(map,dim);
count(map,dim);

for(int i=0;i<dim;i++)
	delete [] map[i];
delete [] map;
}

