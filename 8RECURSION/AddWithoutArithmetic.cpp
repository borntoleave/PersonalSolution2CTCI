//http://zhedahht.blog.163.com/blog/static/254111742011125100605/

#include<iostream>
using namespace std;
int AddWithoutArithmetic(int num1, int num2);
string toBinary(int n);
int main(int argc,char *argv[])
{
	int num1=atoi(argv[1]);
	int num2=atoi(argv[2]);
	cout<<AddWithoutArithmetic(num1,num2)<<endl;
}

int AddWithoutArithmetic(int num1, int num2)
{
    if(num2 == 0)
    return num1;
	int sum = num1 ^ num2;
    int carry = (num1 & num2) << 1;
    cout <<num1<<'\t'<<num2<<'\t'<<sum<<'\t'<<carry<<endl;
    cout <<toBinary(num1)<<'\t'<<toBinary(num2)<<'\t'<<toBinary(sum)<<'\t'<<toBinary(carry)<<endl;
    return AddWithoutArithmetic(sum, carry);
}

string toBinary(int n)
{
    std::string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}

