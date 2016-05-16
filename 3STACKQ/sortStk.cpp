#include"StkQ.h"
#include<ctime>
int main(){
srand(time(NULL));
stk<int> s1;
for(int i=0;i<20;i++)
	s1.push(rand()%20);
cout<<s1;
s1.sort();
cout<<s1;
}
