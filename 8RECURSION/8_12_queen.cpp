// 0 1 0 0 0
// 0 0 0 1 0
// 1 0 0 0 0
// 0 0 1 0 0
// 0 0 0 0 1
#include<iostream>
#include<ctime>
#include<vector>
#include<iomanip>
#define N 8
using namespace std;
void print(vector<vector<int> > b){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cout<<setw(2)<<(b[i][j]==1?"o":".");
		cout<<endl;
	}
	cout<<endl;
}

void fill(vector<vector<int> > &b,int r,int c){
	b[r][c]=1;
	for(int i=0;i<N;i++)
		if(!b[i][c])
			b[i][c]=-1;
	for(int j=0;j<N;j++)
		if(!b[r][j])
			b[r][j]=-1;
	int dir[4][2]={{1,1},{1,-1},{-1,1},{-1,-1}};
	for(int i=1;i<N;i++){
		for(int d=0;d<4;d++)
		if(r+i*dir[d][0]>=0&&c+i*dir[d][1]>=0&&r+i*dir[d][0]<N&&c+i*dir[d][1]<N)
			b[r+i*dir[d][0]][c+i*dir[d][1]]=-1;
		}
}

void find(vector<vector<int> > &b,int r){
	if(r==N){
		print(b);
		return;
	}
	for(int c=0;c<N;c++){
		vector<vector<int> > temp=b;
		if(!b[r][c]){
			fill(temp,r,c);
			find(temp,r+1);
		}
		temp=b;
	}		
}



int main(int argc,char *argv[])
{
 	if(argc!= 1 ){cerr<<"Format: "<<argv[0]<<" < > "<<endl;exit(-1);}
	vector<int> row(0);
	row.resize(N);
	vector<vector<int> > board;
	for(int i=0;i<N;i++){
		board.push_back(row);
		for(int j=0;j<N;j++)
			cout<<board[i][j]<<" ";
		cout<<endl;
	}
 	clock_t start=clock();

	///fill(board,4,6);

	find(board,0);
 	cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	return 0;
}
