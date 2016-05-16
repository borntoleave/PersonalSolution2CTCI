//./a.out 5
#include<iostream>
using namespace std;
void brik(int,int){
	return;
}
void forWithoutIf(int i,int n){
	void (*fun[2])(int,int)={forWithoutIf,brik};
//vvvvv  operations in normal for loop  vvvvv
	cout<<i<<endl;
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	fun[i/n](i+1,n);
}

int main()
{
	forWithoutIf(0,10);
}


