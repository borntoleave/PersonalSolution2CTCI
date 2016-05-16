/* Problem Statement for DoubleOrOneEasy
 
 
 Problem Statement
 You have two positive integers: the first one is a, the second one is b.
 
 
 
 You also have a red button and a blue button.
 
 Whenever you push the red button, both your numbers are incremented by 1.
 
 Whenever you push the blue button, both your numbers are multiplied by 2.
 
 
 
 Your goal is to change the pair (a, b) into the pair (newA, newB).
 
 
 
 You are given the ints a, b, newA, and newB.
 
 If there is a sequence of zero or more button pushes that accomplishes your goal, return the length of the shortest such sequence. Otherwise, return -1.
 
 Definition
 
 Class:	DoubleOrOneEasy
 Method:	minimalSteps
 Parameters:	int, int, int, int
 Returns:	int
 Method signature:	int minimalSteps(int a, int b, int newA, int newB)
 (be sure your method is public)
 
 
 Notes
 -	The operations can produce arbitrarily large integers. For example, if you just push the blue button 1000 times in a row, you will get the numbers a*2^1000 and b*2^1000.
 
 Constraints
 -	a will be between 1 and 1,000,000,000, inclusive.
 -	b will be between 1 and 1,000,000,000, inclusive.
 -	newA will be between 1 and 1,000,000,000, inclusive.
 -	newB will be between 1 and 1,000,000,000, inclusive.
 
 Examples
 0)
 
 100
 1000
 101
 1001
 Returns: 1
 Just push the red button once.
 1)
 
 100
 1000
 202
 2002
 Returns: 2
 The best solution is to push the red button followed by the blue button. This performs the operation +1 followed by the operation *2.
*/

#include<iostream>
#include<ctime>
#include<queue>
#include<cmath>
using namespace std;
int *arg(){
    int *par=new int[4];
    int a=rand()%20-5,b=rand()%20-5;
    par[0]=a;par[1]=b;
    int nOpr=rand()%10+1;
    while(nOpr--){
        int opr=rand()%2;
        if(opr){
            cout<<'+';
            a+=1;b+=1;
        }
        else{
            cout<<'x';
            a*=2;b*=2;
        }
    }
    cout<<endl;
    par[2]=a;par[3]=b;
    for(int i=0;i<4;i++)
        cout<<par[i]<<" ";
    cout<<endl;
    return par;
}

// try ./a.out 3 9 100 196. the methematical method will find the path(xxxxx++++) for 3->100, but it's not correct for 9->196
class node{
public:
    int a;
    int b;
    string opr;
    node(int a,int b):a(a),b(b),opr(""){}
    node * add(){
        node *n=new node(a,b);
        n->a+=1;n->b+=1;
        n->opr=opr+'+';
        return n;
    }
    node * x2(){
        node *n=new node(a,b);
        n->a*=2;n->b*=2;
        n->opr=opr+'x';
        return n;
    }
};

class DoubleOrOneEasy{
public:
    int a,b,newA,newB;
    DoubleOrOneEasy(int a,int b,int na,int nb):a(a),b(b),newA(na),newB(nb){}
    int minimalSteps(int a,int b,int newA,int newB){
        node *init=new node(a,b);
        //node *dest=new node(newA,newB);
        queue<node *> q;
        q.push(init);
        while(!q.empty()){
            node *current=q.front();
            q.pop();
            if(current->a==newA&&current->b==newB){
                cout<<current->opr<<endl;
                return current->opr.length();
            }
            if( (newA&&current->a==newA&&current->b!=newB)
               ||(newB&&current->b==newB&&current->a!=newA)   )
                continue;
            node *x2=current->x2();
            node *add=current->add();
            q.push(add);
            q.push(x2);
        }
    return -1;
    }
    int depthF(int a,int b,int newA,int newB,string opr){
        if(a==newA&&b==newB){
            cout<<opr<<endl;
            return 0;
        }
        if( (a==newA&&b!=newB)  ||  (b==newB&&a!=newA)   )
            return -1;
        if(a*2<=newA&&b*2<=newB){
            opr+='x';
            int s=depthF(a*2,b*2,newA,newB,opr);
            if(s>=0)
                return 1+s;
            else return -1;
        }
        if(a+1<=newA&&b+1<=newB){
            opr+='+';
            int s=depthF(a+1,b+1,newA,newB,opr);
            if(s>=0)
                return 1+s;
            else
                return -1;
        }
        return -1;
    }
    int math(int a,int b,int newA,int newB){
        int dif=a-b,diff=newA-newB;
        if((log2(1.0*diff/dif)-round(log2(1.0*diff/dif)))!=0)
            return -1;
        int mult=log2(diff/dif),div,opr=0;
        while(newA!=a){//try to use newB and b to find the path. they are different。
            div=newA/a/pow(2,mult);
            int adds=newA-a*div*pow(2,mult);
            for(int i=0;i<adds;i++){
                cout<<'+';
                newA-=1;
                opr++;
            }
            if(div){
                cout<<'x';
                newA/=2;
                opr++;
                mult--;
            }
        }
        cout<<endl<<opr<<endl;
        mult=log2(diff/dif);opr=0;
        while(newB!=b){
            div=newB/b/pow(2,mult);
            int adds=newB-b*div*pow(2,mult);
            for(int i=0;i<adds;i++){
                cout<<'+';
                newB-=1;
                opr++;
            }
            if(div){
                cout<<'x';
                newB/=2;
                opr++;
                mult--;
            }
        }
        cout<<endl<<opr<<endl;
        
        return 0;
    }
    
    int math2(int a,int b,int newa,int newb){
        if(log2(1.0*(newb-newa)/(b-a))-round(log2(1.0*(newb-newa)/(b-a)))!=0){
            cout << -1 << endl;
            return 0;
        }
        int n=log2((newb-newa)/(b-a));
        //	cout << n << endl;
        int s=newa-a*pow(2,n);
        if (s<0){
            cout<<-1;
            return 0;
        }
        //	cout << s << endl;
        int m=0, m0=0;
        while(n!=-1){
            m0=s/pow(2,n);
            for(int i=0; i<m0; i++){
                cout << "+";
            }
            m=m+m0;
            s=s-m0*pow(2,n);
            n=n-1;
            if(n!=-1) cout << "x";
        }
        cout << endl;
        //	cout << m << endl;
        return 0;
    }
};

int main(int argc,char *argv[])
{
 	if(argc!= 5 ){cerr<<"Format: "<<argv[0]<<" <a> <b> <newA> <newB> "<<endl;exit(-1);}
    int a=atoi(argv[1]),b=atoi(argv[2]),newA=atoi(argv[3]),newB=atoi(argv[4]);
    srand(time(NULL));
    //int *par=arg();
    //int a=par[0],b=par[1],newA=par[2],newB=par[3];
 	clock_t start=clock();
    cout<<"* BreadthFirst method:"<<endl;
    DoubleOrOneEasy problem(a,b,newA,newB);
    cout<<problem.minimalSteps(a,b,newA,newB)<<endl;
    cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
    string opr="";
    //start=clock();
    //cout<<"* DepthFirst method:"<<endl;
    //cout<<problem.depthF(a,b,newA,newB,opr)<<endl;
    //cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
    start=clock();
    cout<<"* Mathematical method:"<<endl;
    problem.math2(a,b,newA,newB);
 	cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	return 0;
}
