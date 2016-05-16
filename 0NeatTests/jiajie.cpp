#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
double **Weak,**Strong;
void print(double **arr,int dim){
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++)
			cout<<setw(3)<<(arr[i][j]?arr[i][j]:0)<<" ";
		cout<<endl;
	}
}

int main(){
	ifstream strong("./StrongFile.txt",ios::in);
	ifstream weak("./WeakFile.txt",ios::in);
	string buff;
	Weak=new double*[26];Strong=new double*[26];
	for(int i=0;i<26;i++){
		Weak[i]=new double[26];
		Strong[i]=new double[26];}
	int c=0;
	while(strong>>buff){
		cout<<buff<<endl;
		c++;
		int len=buff.length();
		for(int i=0;i<len;i++)
			for(int j=0;j<len;j++)
				if(i!=j)
					Strong[buff[i]-'A'][buff[j]-'A']=1;
	}
	print(Strong,c);
	c=0;
	while(weak>>buff){
	cout<<buff<<endl;
	c++;
	int len=buff.length();
	for(int i=0;i<len;i++)
		for(int j=0;j<len;j++)
			if(i!=j)
				Weak[buff[i]-'A'][buff[j]-'A']=0.5;
}
print(Weak,c);
	

}
