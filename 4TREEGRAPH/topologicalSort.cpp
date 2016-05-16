#include<iostream>
#include<ctime>
#include<set>
#include<queue>
using namespace std;
/*
    1   2   3   4   5
1       1   1   1
2                   1
3                   1
4                   1
5
*/
void top(int adj[][2]){
    int **mat=new int *[6];
    for(int i=1;i<6;i++)
        mat[i]=new int[6]();
    for(int i=0;i<6;i++)
        mat[adj[i][0]][adj[i][1]]=1;//adj mat
    int *in=new int[6]();
    for(int c=1;c<6;c++)
        for(int r=1;r<6;r++)
            in[c]+=mat[r][c];
    for(int i=1;i<6;i++)
        cout<<in[i]<<" ";
    cout<<endl;
    int v=5;
    while(v){
        for(int i=1;i<6;i++){
            if(!in[i]){
                cout<<i<<" ";
                in[i]=-1;
                for(int j=1;j<6;j++)
                    if(mat[i][j]){
                        mat[i][j]=0;
                        in[j]--;
                    }
                v--;
                break;
            }
            continue;
        }
        
        
    }
            
    
}


void top2(int adj[][2]){
    int *in=new int [6]();

    queue<int> q;
    for(int i=0;i<6;i++)
        in[adj[i][1]]++;
    for(int v=1;v<6;v++)
        if(in[v]==0){
            q.push(v);
            in[v]=-1;
        }
    while(!q.empty()){
        int cur=q.front();
        cout<<cur<<" ";
        q.pop();
        for(int l=0;l<6;l++)
            if(adj[l][0]==cur){
                in[adj[l][1]]--;
                if(in[adj[l][1]]==0)
                    q.push(adj[l][1]);
            }
    
    
    }


}

int main(int argc,char *argv[])
{
 	if(argc!= 1 ){cerr<<"Format: "<<argv[0]<<" < > "<<endl;exit(-1);}
	srand(time(NULL));
 	clock_t start=clock();

    int adj[6][2]={{2,5},{1,4},{4,5},{1,2},{1,3},{3,5}};
    top(adj);
    cout<<endl;
    top2(adj);

 	cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	return 0;
}
