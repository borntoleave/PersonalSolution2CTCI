#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    vector<int> a,b;map<int,vector<int> > occ;
    
    a.push_back(1);a.push_back(2);
    b.push_back(1);b.push_back(2);
    cout<<(a==b)<<endl;
    a.push_back(3);
    cout<<(a==b)<<endl;
    occ.insert(make_pair(3,a));
    cout<<occ[3][1]<<endl;
}