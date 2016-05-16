#include<iostream>
#include<array>
#include<vector>
#include<iomanip>
using namespace std;
template <class Type>
class matrix:public vector<Type>
{
 	vector< vector<Type> > mat;
 	int row,col;
 public:
	matrix(int m,int n,int elm=0):row(m),col(n){
		for(int i=0;i<m;i++){
			vector<Type> row;
			for(int j=0;j<n;j++)
				row.push_back(elm);
			mat.push_back(row);
		}
 	}
 friend 
 	ostream& operator <<(ostream & o,matrix & m){
		for(int i=0;i<m.row;i++){
			for(int j=0;j<m.col;j++)		
				o<<setw(3)<<m.mat[i][j]<<' ';
			o<<endl;
		}
		return o;
 	}
};

int main(int argc,char *argv[]){
	if(argc!= 1 ){cerr<<"Format: "<<argv[0]<<" < > "<<endl;exit(-1);}
 	matrix<int> m(10,5,2); 
 	cout<<m;
 	return 0;
}
