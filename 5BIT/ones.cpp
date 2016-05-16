#include<iostream>
#include<string>
using namespace std;

class num{
public:
	int n;
	
	num(int d=0):n(d){}
	string convert(int base){
		int orig=n>=0?n:(~n+1);
		string s="";
		char b16[]={'A','B','C','D','E','F'};
		while (orig){
			char dig=(orig%base>10?b16[orig%base-10]:orig%base+'0');
			s+=dig;
			orig/=base;
		}
		if(n<0)
			s+="-";
		if(base==16)
			s+="x0";
		int len=s.length();
		for(int i=0;i<len/2;i++){
			s[i]^=s[len-i-1];
			s[len-i-1]^=s[i];
			s[i]^=s[len-i-1];
		}
		return s;
	}

	int nOfOnes(){
		int orig=n,c=0;
		while(orig){
			orig&=(orig-1);
			c++;
		}
		return c;
	}
};
int main(int argc,char * argv[]){
	if(argc!= 2 ){
		cerr<<"Format: "<<argv[0]<<" <num> "<<endl;
		exit(-1);
	}
	num n(atoi(argv[1]));
	cout<<n.n<<"\t_b10"<<endl
		<<n.convert(2)<<"\t_b2\t"
		<<n.nOfOnes()<<" ones in binary"<<endl
		<<n.convert(8)<<"\t_b8"<<endl
		<<n.convert(16)<<"\t_b16"<<endl;

	num m(1);
	m.n=~m.n<<3;
	cout<<m.n<<' '<<m.convert(2)<<endl;	

	num k(-1);
	cout<<k.convert(2)<<endl;
}
