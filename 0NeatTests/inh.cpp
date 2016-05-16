#include<iostream>
#define PI 3.1415926
using namespace std;
template <class Type>

class point
{
 protected:
 	Type x,y;
 public:
 	point(Type x=0,Type y=0):x(x),y(y){cout<<"Constructor P"<<x<<endl;}
 	virtual ~point(){cout<<"Destructor P"<<x<<endl;}
 	virtual Type area()const{return 0;}
 friend ostream & operator << (ostream & o, point & p){
	o<<"["<<p.x<<","<<p.y<<"]"<<endl;
	return o;
	}		
 point operator + (point b){
	point c;
	c.x=x+b.x;
	c.y=y+b.y;
	return c;
 	}
 void operator +=(point b){
 	x+=b.x;
 	y+=b.y;
 	}	
};
template <class Type>
class circle:public point<Type>
{
 protected:
 	Type r;
 public:
 	circle(Type x,Type y,Type r=0):point<Type>(x,y),r(r){
 		cout<<"Constructor c"<<r<<endl;}
 	~circle(){cout<<"Destructor c"<<r<<endl;}
 	Type area(){
		return PI*r*r;
 		} 	
 friend ostream & operator <<(ostream & o, circle & c){
	o<<"Center = ["<<c.x<<","<<c.y<<"]\tRadius = "<<c.r<<"\tArea = "<<c.area()<<endl;
	return o;
 	}

};
template <class Type>
class cylinder:public circle<Type>
{
 protected:
 	Type h;
 public:
 	cylinder(Type x, Type y, Type r, Type h=0):circle<Type>(x,y,r),h(h){
 		cout<<"Constructor C"<<h<<endl;}
 	~cylinder(){cout<<"Destructor C"<<h<<endl;}
 	Type area(){
		return 2*circle<Type>::area()+2*PI*circle<Type>::r*h;
 		}
 	Type volume(){
		return circle<Type>::area()*h;
 		}	
 friend ostream& operator <<(ostream& o,cylinder &C){
	o<<"Center = ["<<C.x<<","<<C.y<<"]\tRadius = "<<C.r<<"\tHeight = "<<C.h
	 <<"\tSurface Area = "<<C.area()<<"\tVolume = "<<C.volume()<<endl;
	return o;
 	}
};

int main(int argc,char *argv[])
{
 if(argc!= 1 ){cerr<<"Format: "<<argv[0]<<" < > "<<endl;exit(-1);}
 point<double> p1(2,1);
 point<double> p2(5,6);
 point<double> c=p1+p2;
 cout<<p1<<p2<<c;
 c+=p2;
 cout<<c;
 circle<double> cl(1,2,5);
 cout<<cl;
 cylinder<double> cd(3,4,5,6);
 cout<<cd;
	


 return 0;
}
