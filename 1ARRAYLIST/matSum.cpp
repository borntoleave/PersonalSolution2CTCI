#include<iostream>
using namespace std;
void set(int *mat[],int cols,int rows){
for(int row=0;row<rows;row++){
	for(int col=1;col<cols;col++)		
		mat[row][col]+=mat[row][col-1]	;					
		if(row>0)
			for(int col=0;col<cols;col++)
				mat[row][col]+=mat[row-1][col];
	}
}

void set2(int *mat[],int cols,int rows){
	for(int row=0;row<rows;row++)
		for(int col=0;col<cols;col++){		
			if(col>0)
				mat[row][col]+=mat[row][col-1];					
			if(row>0)
				mat[row][col]+=mat[row-1][col];
			if(col>0&&row>0)
				mat[row][col]-=mat[row-1][col-1];
		}
}

int main(){
	int **mat=new int *[3];
	for(int i=0;i<3;i++){
		mat[i]=new int [3];
		for(int j=0;j<3;j++)
			mat[i][j]=1;
			}

	set(mat,3,3);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
		}
cout<<endl;

for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			mat[i][j]=1;
			}

	set2(mat,3,3);
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
		}

}


