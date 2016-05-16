#include<iostream>
#include<ctime>
using namespace std;
int ct=0;
void tellstory(int i){
	if(i<=0){
		cout<<"  Baby, I have no story to tell."<<endl;
		return;	
	}
	cout<<"  There was a mountain, and a temple on it."<<endl
		<<"  An old monk was telling two stories."<<endl
		<<"One story was:"<<endl
		<<++ct<<".";
	tellstory(i-rand()%2);
	cout<<"The other story was:"<<endl
		<<++ct<<".";
	tellstory(i-rand()%2);
}

int main(int argc,char *argv[])
{
	srand(time(NULL));
 	clock_t start=clock();
 	
	tellstory(2);

 	cout<<ct<<" stories were told in "<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
}

