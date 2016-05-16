#include<iostream>
#include<ctime>
#include<vector>
#include<set>
using namespace std;
vector<int> init(){
    vector<int> v;
    for(int i=0;i<4;i++)
        v.push_back(rand()%13+1);
    return v;
}

void vecDisp(const vector<int> &vec){
    for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<" ";
    cout<<endl;
}


double calc(const double &a,const double &b,const int &opr){
    switch(opr){
        case 0:return a+b;
        case 1:return a-b;
        case 2:return 1.0*a*b;
        case 3:return 1.0*a/b;
    }
}
void oprPerm(vector<int> & v,string expr,double result,int layer){
    if(layer==3){
        if(result==24){
            cout<<expr<<endl;
        }
        result=0;
        expr="";
        return;
    }
    if (layer==0){
        result=v[0];
        expr=to_string(v[0]);
    }
    char opr[4]={'+','-','x','/'};
    
    for(int o=0;o<4;o++){
        double tempRes=result;
        string tempStr=expr;
        tempRes=calc(result,v[layer+1],o);
        tempStr+=opr[o];
        tempStr+=to_string(v[layer+1]);
        oprPerm(v,tempStr,tempRes,layer+1);
    }
}

void numPerm(set<vector<int> > & s,vector<int> &v,vector<int> order,int layer){
    if(layer==4){
        if(s.find(order)==s.end()){
            //vecDisp(order);
            //s.insert(order);
            string expr;double result;
            oprPerm(order,expr,result,0);
        }
        return;
    }
    for(int i=0;i<v.size();i++){
        if(v[i]){
            order.push_back(v[i]);
            v[i]=0;
            numPerm(s,v,order,layer+1);
            v[i]=order.back();
            order.pop_back();
        }
    }
}

int main(int argc,char *argv[])
{
    if(argc!= 1 ){cerr<<"Format: "<<argv[0]<<" < > "<<endl;exit(-1);}
    srand(time(NULL));
    clock_t start=clock();
    vector<int> v=init();
    vecDisp(v);
    cout<<endl;
    set<vector<int> > perm;
    vector<int>order;
    cout<<"Calculation is done from left to right, regardless of priorities"<<endl;
    numPerm(perm,v,order,0);
    
    cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
    return 0;
}
