//create N stacks using one array. automatically double size when filled up.
#include<iostream>
using namespace std;
template<class Type>
class stkN{
 private:
 	Type *arr;
 	int *top,bin,size,cur;
 public:
 	stkN(int n=3,int s=100):arr(new Type[s]),top(new int[n]),bin(n),size(s),cur(0){
		for(int i=0;i<n;i++)
			top[i]=-1;
		}
	~stkN(){}
	void push(int n,Type d){
		if(cur>=size){
			cerr<<endl<<"Stack is full! Creating new memory!"<<endl
				<<"Original address: \t"<<arr<<endl;
			Type *dubli=new Type(2*size);
			for(int i=0;i<cur;i++)
				dubli[i]=arr[i];
			size*=2;
			arr=dubli;
			cerr<<"New address: \t\t"<<arr<<endl;
			}
		arr[cur++]=d;
		arr[cur++]=top[n];
		top[n]=cur-2;
	}
	Type pop(int n){
		if(top[n]<0){
			cerr<<"Stack "<<n<<" is empty!"<<endl;
			return 0;
		}
		Type t=arr[top[n]];
		top[n]=arr[top[n]+1];
		return t;
	}
};

int main(int argc,char *argv[])
{
 if(argc!= 1 ){cerr<<"Format: "<<argv[0]<<" < > "<<endl;exit(-1);}
 stkN<int> s(4,100);
 for(int i=1;i<19;i++)
  	for(int j=0;j<4;j++){
		cout<<i*20+j<<' ';
 		s.push(j,i*20+j);
 	}
cout<<"Finished initialization."<<endl;
 for(int i=0;i<4;i++){
 	cout<<"Stack "<<i<<": ";
 	for(int j=1;j<19;j++)
 		cout<<s.pop(i)<<' ';
 	cout<<endl;
 	}
 return 0;
}


