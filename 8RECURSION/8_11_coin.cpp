#include<iostream>
#include<list>
#include<set>
#include<cmath>
#include<string>
#include<ctime>
#include<iomanip>
using namespace std;
int ct=0;
string listV(list<int> l){
    string s="";
    for(list<int>:: iterator it=l.begin();it!=l.end();it++){
        s+=*it+'0';
    }
    return s;
}

void find(int * coin,int value,list<int> l,set<string > &history){
    for(int i=0;i<4;i++){
        if(value-coin[i]<0)
            return;
        l.push_back(coin[i]);
        value-=coin[i];
        if(!value){
            l.sort();
            string hash=listV(l);
            if(history.find(hash)==history.end()){
                history.insert(hash);
                cout<<setw(2)<<++ct<<": ";
                for(list<int>::iterator it=l.begin();it!=l.end();it++)
                    cout<<*it<<' ';
                cout<<endl;
            }
            return;
        }
        find(coin,value,l,history);
        l.pop_back();
        value+=coin[i];
        
    }
}

void find_opt(int * coin,int value,int last,list<int> l){
    for(int i=last;i<5;i++){
        if(value-coin[i]<0)
            return;
        l.push_back(coin[i]);
        value-=coin[i];
        if(!value){
            cout<<setw(2)<<++ct<<" : ";
            for(list<int>::iterator it=l.begin();it!=l.end();it++)
                cout<<*it<<' ';
            cout<<endl;
            return;
        }
        find_opt(coin,value,i,l);
        l.pop_back();
        value+=coin[i];
    }
}

void find2(int *coin,int value,int *memo){
    for(int i=0;i<5;i++){
        if(value-coin[i]<0)
            return;
        //if(value-coin[i]==)
        
        
    }
}

int main(int argc,char *argv[])
{
    if(argc!= 2 ){
        cerr<<"Format: "<<argv[0]<<" <Value> "<<endl;
        exit(-1);
    }
    int v=atoi(argv[1]);
    int coin[4]={1,5,10,25};
    list<int> combination;
    set<string > history;
    clock_t start;
    cout<<"The combinations to make "<<v<<" cents are:"<<endl;
    start=clock();
    find(coin,v,combination,history);
    cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
    history.clear();combination.clear();ct=0;
    start=clock();
    find_opt(coin,v,0,combination);
    cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
    
    
    
    return 0;
}
