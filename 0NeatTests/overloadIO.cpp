//RzL, Nov 5, 2015
//reload the '<<' operator to print array elements. the type of the array is flexible using template.

#include<iostream>
using namespace std;
template <class Type>
class array
{
 private:
	Type *a;
	int size;
 public:
 	array(int n){
 		a=new Type [n];
 		for (int i=0;i<n;i++)
 			a[i]=Type(NULL);
 		size=n;
 	}
 	array(Type *init,int n){
		a=new Type [n];
		for(int i=0;i<n;i++)
			a[i]=*(init+i);
		size=n;
 	}
 	~array(){}
 friend inline ostream &operator << (ostream & os,array &x){ //friend inline ostream, inline is optional
		cout<<"{ ";
		for(int i=0;i<x.size;i++)
			cout<<x.a[i]<<' ';
		cout<<"}"<<endl;
		return os;
		}
 friend inline istream &operator >> (istream & is,array &x){
 		for(int i=0;i<x.size;i++)
			cin>>x.a[i];
		return is;
		}
};

int main(int argc, char * argv[])
{
 int n=atoi(argv[1]);
 array<int> x(n);
 cout<<x;
 char ch[3]={'h','i','!'};
 array<char> y(ch,3);
 cout<<y;
 string str[2]={"Hello","world!"}; 
 array<string> z(str,2);
 cout<<z;
 cin>>z;
 cout<<z;
}
