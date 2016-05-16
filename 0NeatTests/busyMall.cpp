//Busiest Time in The Mall

//The mall management is trying to figure out what was the busiest moment in the mall in the last year.
//You are given data from the door detectors: each data entry includes a timestamp (seconds in Unix Epoch format), an amount of people and whether they entered or exited.

//Example of a data entry:
//{ time: 1440084737,  count: 4,  type: "enter" }

//Find what was the busiest period in the mall on the last year. Return an array with two Epoch timestamps representing the beginning and end of that period. You may assume that the data your are given is accurate and that each second with entries or exists is recorded. Implement the most efficient solution possible and analyze its time and space complexity.

#include<iostream>
#include<ctime>
using namespace std;

template<class T1,class T2,class T3>
class ele{
public:
	T1 a;
	T2 b;
	T3 c;
	ele(){
		string type[2]={"enter","exit"};
		a=rand()%1000000+1000000;
		b=rand()%9+1;
		c=type[rand()%2];
	}
	~ele(){}
	friend ostream & operator <<(ostream &o,ele &e){
		o<<e.a<<" "<<e.b<<" "<<e.c<<endl;
		return o;
	}
};

void swap(ele<long,unsigned,string> &e1,ele<long,unsigned,string> &e2){
	if(e1.a==e2.a)
		return;
	long temp;
	temp=e1.a;
	e1.a=e2.a;
	e2.a=temp;
}
ele<long,unsigned,string> * createData(int len){
	ele<long,unsigned,string> *list=new ele<long,unsigned,string>[len]; 
	for(int l=0;l<len;l++){
		cout<<list[l];
		}
	return list;
}

void sort(ele<long,unsigned,string> *&list,int beg,int end){  //bugs
	if(beg>=end)
		return;
	long pivot=list[beg].a,cur=beg+1,left=beg,right=end;
	while(beg<right){
		if(list[cur].a<pivot&&beg<right){
			swap(list[left++],list[cur++]);
		}
		else if(list[cur].a>=pivot&&beg<right)
			swap(list[right--],list[cur]);
		
	}
	list[left].a=pivot;
	sort(list,beg,left-1);
	sort(list,left+1,end);
	
	

}

int main(int argc,char *argv[])
{
 	if(argc!= 1 ){cerr<<"Format: "<<argv[0]<<" < > "<<endl;exit(-1);}
	srand(time(NULL));
 	clock_t start=clock();
	ele<long,unsigned,string> *list;
	list=createData(10);
	cout<<endl;
	sort(list,0,10);	
	for(int i=0;i<10;i++)
		cout<<list[i];
 	cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	return 0;
}
