#include<iostream>
#include<iomanip>

using namespace std;
int main(int argc,char *argv[])
{
 if(argc!= 1 ){cerr<<"Format: "<<argv[0]<<" < > "<<endl;exit(-1);}
 int m[5][5]={
        {1, 2, 3, 4,5},
 		{5, 0, 7, 8,6},
 		{9,10,11,12,7},
 		{1, 2, 0, 4,8},
 		{5, 6, 7, 8,9}};
 int r0=0,c0=0;
 for(int i=0;i<5;i++)
 	if(!m[i][0]){
 		c0=1;
 		break;
 	}
 
 for(int j=0;j<5;j++)
 	if(!m[0][j]){
 		r0=1;
 		break;
 	}
 for(int i=0;i<5;i++)
 	for(int j=0;j<5;j++)
 		if(!m[i][j]){
			m[i][0]=0;
 			m[0][j]=0;
		}
			
 for(int i=0;i<5;i++)
	if(!m[i][0])
		for(int j=0;j<5;j++)	
			m[i][j]=0;
 for(int j=0;j<5;j++)
	if(!m[0][j])
		for(int i=0;i<5;i++)	
			m[i][j]=0;
 
 
 if(c0)
 	for(int i=0;i<5;i++)
 		m[i][0]=0;
 if(r0)
 	for(int j=0;j<5;j++)
 		m[0][j]=0;
 	
 for(int i=0;i<5;i++){
 	for(int j=0;j<5;j++)
 		cout<<setw(3)<<m[i][j]<<' ';
 	cout<<endl;
 }

 return 0;
}
