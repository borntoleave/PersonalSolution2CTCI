#include<iostream>
#include<ctime>
#include<list>
using namespace std;

class state{
public:
    string st;
    int num;
    list<double> prob;
    list<state *> next;
    state(string s):st(s),num(0){
    }
    ~state(){}
    void addNext(state * node,double p){
        next.push_back(node);
        prob.push_back(p);
        num++;
    }
    //------------------
  /*  int experiment(){
        int step=0;
        while(1){
            int nt=rand()%2;
            step++;
            bool result=addNext(next[nt]);
            if(result)return step;
        }
    }*/
    
    void printNext(){
        for(std::list<state *> ::iterator it=next.begin();it!=next.end();it++)
            cout<<(*it)->st<<" ";
        cout<<endl;
    }
};

int main(int argc,char *argv[])
{
    if(argc!= 1 ){cerr<<"Format: "<<argv[0]<<" < > "<<endl;exit(-1);}
    srand(time(NULL));
    clock_t start=clock();
    state *init=new state("");
    state *head=new state("h");
    state *tail=new state("t");
    init->addNext(head,0.5);
    init->addNext(tail,0.5);
    //head->addNext(head,0.5);
    head->addNext(tail,0.5);
    tail->addNext(head,0.5);
    tail->addNext(tail,0.5);
    
    init->printNext();
    head->printNext();
    tail->printNext();
    
    
    
    double aver=0;
    for(int i=0;i<100000;i++)
  ;
    cout<<1.0*aver/100000<<endl;
        
        
        cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
    return 0;
}
