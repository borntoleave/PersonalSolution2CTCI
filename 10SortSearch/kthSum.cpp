#include<iostream>
#include<ctime>
#include<list>
using namespace std;

void printL(list<int> &l){
    for(list<int>::iterator it=l.begin();it!=l.end();it++)
        cout<<*it<<" ";
    cout<<endl;

}
using namespace std;
int main(){
    srand(time(NULL));
    int m=20,n=30;
    list <int> a,b;
    for(int i=0;i<m;i++)
        a.push_back(rand()%100);
    for(int i=0;i<n;i++)
        b.push_back(rand()%100);
    a.sort();b.sort();
    printL(a);
    printL(b);
    list<int>::iterator ita=a.begin(),itb=b.begin();
    int i=0,j=0;
    int kth=4;
    for(int k=0;k<kth-1;k++){
        for(int pop=0;pop<2;pop++){
            if(*ita<*itb)
                ita++;
            else itb++;
        }
    }
    cout<<*ita<<" "<<*itb<<endl;
        



}