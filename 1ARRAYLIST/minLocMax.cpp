#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void minLoc(long *extr,long nLoc,long nV){
    if(nV>=extr[1]&&nLoc<extr[0]){
        extr[0]=nLoc;
        extr[1]=nV;
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long n,p,q,m_p,m,
        *extr=new long[2];
    cin>>n;
    long *arr=new long[n];
    for (int i=0;i<n;i++)
        cin>>arr[i];
    cin>>p>>q;//p q
    extr[0]=q;extr[1]=-1;//0 as location, 1 as value;
    if(q<=arr[0])
        cout<<p;
    else if (p>=arr[n-1])
        cout<<q;
    else{
        long beg=0,end=n-1;
        for(int i=0;i<n;i++){
            if(arr[i]<p)beg=i;
            if(arr[i]<q)end=i;}
         cout<<arr[beg]<<' '<<arr[end]<<endl;
        for(int i=beg;i<end+1&&i<n-1;i++){
          	m_p=arr[i]+(arr[i+1]-arr[i])/2;
           	m=(arr[i+1]-arr[i])/2;
        		if(m_p>=p&&m_p<=q)
            		minLoc(extr,m_p,m);
        }

        m_p=p;
        m=min(abs(p-arr[beg]),abs(p-arr[beg-1]));
        minLoc(extr,m_p,m);
        m_p=q;    
        m=min(abs(q-arr[end]),abs(q-arr[end+1]));
        minLoc(extr,m_p,m);   
        cout<<extr[0];
    }
    
    return 0;
}


