//tested Floyd-Warshall and Dijkstra's algorithm
#include<iostream>
#include<ctime>
#include<iomanip>
#include<string>
#include<set>
#define $ (INT_MAX/2-1)
using namespace std;
void print(int **arr,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==$)
                cout<<"      ";
            else
                cout<<setw(6)<<arr[i][j];
        }
        cout<<endl;
    }
}
int ** init(int n){
    int arr[7][7]={
        { 0, $, $, $, $, $, 9},
        {20, 0,10,30, $, $, $},
        { $, $, 0, $, 5, $, $},
        { $, $, $, 0, $, $, $},
        { $, $, $,12, 0, $,15},
        { $, $, $, $, 8, 0,10},
        { $, $,18, $, $, $, 0}  };
    int **dist=new int *[n];
    for(int i=0;i<n;i++){
        dist[i]=new int [n];
        for(int j=0;j<n;j++)
            dist[i][j]=arr[i][j];
    }
    return dist;
}

void FW(int ** dist,int n){
    string ** path=new string*[n];
    for(int i=0;i<n;i++){
        path[i]=new string[n]();
        for(int j=0;j<n;j++)
            if(dist[i][j]!=$&&i!=j){
                path[i][j]+=i+'a';
                path[i][j]+=j+'a';
            }
    }//initialize path
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(j!=i)
                    if(dist[i][j]>dist[i][k]+dist[k][j]){
                        dist[i][j]=dist[i][k]+dist[k][j];   //update dist
                        path[i][j]=path[i][k];              //update path
                        path[i][j].pop_back();
                        path[i][j]+=path[k][j];
                    }
    cout<<"Floyd-Warshall Distance"<<endl;
    print(dist,n);                  //print dist
    cout<<"Floyd-Warshall Path"<<endl;
    for(int i=0;i<n;i++){           //print path
        for(int j=0;j<n;j++)
            cout<<setw(6)<<path[i][j];
        cout<<endl;
    }
}


int findMin(int **dist,int idx,set<int> V){
    int min=$,min_c=-1;
    for(set<int>::iterator it=V.begin();it!=V.end();it++){
        int d=dist[idx][*it];
        if(d!=$&&d<min){
            min=d;
            min_c=*it;
        }
    }
    return min_c;
}

void dPath(int ** dist,int n,int idx){
    string* path=new string [n];
    for(int j=0;j<n;j++)
        if(dist[idx][j]!=$&&idx!=j){
            path[j]+=idx+'a';
            path[j]+=j+'a';
        }
    set<int> V,S;
    for(int i=0;i<n;i++){
        V.insert(i);
    }
    while(!V.empty()){
        int cur=findMin(dist,idx,V);
        if(cur<0)
            break;
        S.insert(cur);
        V.erase(cur);
        for(set<int>::iterator it=V.begin();it!=V.end();it++){
            if(dist[idx][*it]>dist[idx][cur]+dist[cur][*it]){
                dist[idx][*it]=dist[idx][cur]+dist[cur][*it];
                path[*it]=path[cur];
                path[*it]+=*it+'a';
            }
        }
    }
    cout<<endl<<"Dijkstra Distance"<<endl;
    for (int i=0;i<n;i++){
        if(dist[idx][i]==$)
            cout<<"      ";
        else
            cout<<setw(6)<<dist[idx][i];
    }
    cout<<endl<<"Dijkstra Path"<<endl;
    for (int i=0;i<n;i++)
        cout<<setw(6)<<path[i];
    cout<<endl;
}

int main(int argc,char *argv[])
{
    if(argc!= 1 ){cerr<<"Format: "<<argv[0]<<" < > "<<endl;exit(-1);}
    srand(time(NULL));
    clock_t start;
    int n=7;
    int **dist=init(n);
    cout<<"Adjacent Matrix"<<endl;
    print(dist,n);
    start=clock();
    FW(dist,n);
    cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
    dist=init(n);
    start=clock();
    dPath(dist,n,1);
    cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
    start=clock();
    dPath(dist,n,6);
    cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
    return 0;
}
