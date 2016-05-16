#include<iostream>
using namespace std;
class point{
 private:
	double x,y;
 public:
 	point(double x=0,double y=0):x(x),y(y){}
	double getX(){return x;}
	double getY(){return y;}
};

int main(){
	point p(2,3);
	point *t;
	t=&p;
	cout<<p.getX()<<endl
		<<t->getY()<<endl;
}
