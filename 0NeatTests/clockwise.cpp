//RzL Jan10,2015
#include<iostream>
#include<cmath>
#define PI 3.1415926
using namespace std;
int main()
{	int mat[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	for (int k=0;k<4;k++)	{		//display matrix
		for (int l=0;l<4;l++)
			cout <<mat[k][l]<<'\t';
		cout <<endl;
	}
	cout<<"print clockwisely:"<<endl;
	int i,j,count;double theta;
	i=j=count=theta=0;
	while(count<16)
	{	if(i>=0&&i<4&&j>=0&&j<4&&mat[i][j]!=-1)
		{	cout//<<"mat["<<i<<' '<<j<<"]="
				<<mat[i][j]<<' ';
			mat[i][j]=-1;
			i+=round(sin(theta));
			j+=round(cos(theta));
			count++;
		}
		else
		{	i-=round(sin(theta));	//undo increament
			j-=round(cos(theta));
			theta+=PI/2;
			i+=round(sin(theta));
			j+=round(cos(theta));
		}
	}
	cout <<endl;	
}
