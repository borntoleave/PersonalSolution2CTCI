#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

template<class Type> class compare{
private:
	Type a,b;
public:
	compare(Type a,Type b):a(a),b(b){}
	Type max(){
		return a>=b?a:b;
	}
};

int main(int argc,char *argv[]){
	compare<int> c(1,2);
	compare<double> c1(1.1,2.2);
	compare<string> c2("abc","bc");
	cout<<c.max()<<endl;
	cout<<c1.max()<<endl;
	cout<<c2.max()<<endl;

	vector<double> arr;
	for(int i=0;i<10;i++)
		arr.push_back(sqrt(i));

}
