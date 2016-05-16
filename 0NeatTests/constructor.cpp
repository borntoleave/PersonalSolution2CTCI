#include<iostream>
int n=0;
using namespace std;
class con{
 public:
 	int i;
 	con(){	
 		cout<<"call "<<n++<<endl;}
};

void print(int j){
	if(!j)
		return;
	j--;
	print(j);
	cout<<j<<endl;
}

int main(){
	con *a=new con[20];
	print(10);
}
