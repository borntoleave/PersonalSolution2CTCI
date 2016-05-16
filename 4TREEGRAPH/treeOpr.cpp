#include<iostream>
#include<ctime>
#include<queue>
#include<iomanip>
#include<cmath>
#define wid 5
using namespace std;

template<class type>
class treeNode{
public:
    type d;
    treeNode * l;
    treeNode * r;
    treeNode(type n):d(n),l(NULL),r(NULL){}
    ~treeNode(){}
};

template<class type>
class tree{
public:
    treeNode<type> * root;
    tree():root(NULL){}
    ~tree(){}
    
    void insert(treeNode<type> *& cur,int a){
        treeNode<type> * child=new treeNode<type>(a);
        if(cur==NULL){
            cur=child;
            return;
        }
        if(cur->d > a)
            insert(cur->l,a);
        else
            insert(cur->r,a);
    }
    
    void inTraverse(treeNode<type> *cur){
        if(cur==NULL)
            return;
        inTraverse(cur->l);
        cout<<cur->d<<" ";
        inTraverse(cur->r);
    }
    
    void preTraverse(treeNode<type> *cur){
        if(cur==NULL)
            return;
        cout<<cur->d<<" ";
        preTraverse(cur->l);
        preTraverse(cur->r);
    }
    
    void breadthFirst(){
        queue<treeNode<type> *> q;
        q.push(root);
        while(!q.empty()){
            treeNode<type> * cur=q.front();
            q.pop();
            cout<<cur->d<<" ";
            if(cur->l!=NULL)
                q.push(cur->l);
            if(cur->r!=NULL)
                q.push(cur->r);
        }
    }
    
    int width(treeNode<type> *cur){
        if(cur==NULL)
            return 0;
        int w=width(cur->l)+width(cur->r)+1;
        //cout<<cur->d<<" "<<w<<endl;
        return w;
    }
    
    int height(treeNode<type> *cur){
        if(cur==NULL)
            return 0;
        return max(height(cur->l),height(cur->r))+1;
    }
    
};

template<class type>
class detailNode{
public:
    type data;
    int depth;
    int height;
    int width;
    int shift;
    detailNode *l;
    detailNode *r;
    detailNode(type dt=0,int dp=-1,int ht=-1,int wt=-1,int s=-1):
    data(dt),depth(dp),height(ht),width(wt),shift(s),l(NULL),r(NULL){}
    ~detailNode(){}
};

template<class type>
class detailTree{
public:
    detailNode<type> *root;
    detailTree():root(NULL){}
    ~detailTree(){}
    
    
    int width(detailNode<type> *cur){
        if(cur==NULL)
            return 0;
        cur->width=max(width(cur->l)+width(cur->r),wid);
        return cur->width;
    }
    
    int height(detailNode<type> *cur){
        if(cur==NULL)
            return 0;
        cur->height=max(height(cur->l),height(cur->r))+1;
        return cur->height;
    }
    
    void init(tree<type> t){
        fillData(root,t.root,1);
        fillInfo(root);
        fillShift(root,0);
    }
    
    void clearInfo(detailNode<type>* cur){
        if(cur==NULL)
            return;
        fillInfo(cur->l);
        cur->height=-1;
        cur->width=-1;
        cur->shift=-1;
        fillInfo(cur->r);

    }
    
    void fillData(detailNode<type> *&dCur,treeNode<type> *sCur,int depth){
        if(sCur==NULL)
            return;
        if(dCur==NULL)
            dCur=new detailNode<type>;
        if(sCur->l!=NULL){
            dCur->l=new detailNode<type>;
            fillData(dCur->l,sCur->l,depth+1);
        }
        dCur->data=sCur->d;
        dCur->depth=depth;
        if(sCur->r!=NULL){
            dCur->r=new detailNode<type>;
            fillData(dCur->r,sCur->r,depth+1);
        }
    }
    
    void fillInfo(detailNode<type> *cur){
        if(cur==NULL)
            return;
        fillInfo(cur->l);
        cur->height=height(cur);
        cur->width=width(cur);
        
        fillInfo(cur->r);
    }
    
    void fillShift(detailNode<type> *cur,int shift){
        if(cur==NULL)
            return;
        cur->shift=shift;
        int s;
        if(cur->l!=NULL){
            fillShift(cur->l,shift);
            s=cur->l->width;
        }
        else s=0;
        if(cur->r!=NULL)
            fillShift(cur->r,shift+s);
    }

    void balance(detailNode<type>* &cur){
        if(cur==NULL)
            return;
        int hl,hr;
        if(cur->l==NULL)
            hl=0;
        else hl=cur->l->height;
        if(cur->r==NULL)
            hr=0;
        else hr=cur->r->height;

            if(hr-hl>=2)
                rotateL(cur);
            else
                rotateR(cur);
        clearInfo(cur);
            fillInfo(cur);
            fillShift(cur,0);
        
   //     balance(cur->l);
     //   balance(cur->r);
    }
    
    void rotateL(detailNode<type>*&cur){
        detailNode<type> *right=cur->r;
        cur->r=right->l;
        right->l=cur;
        cur=right;
    }
    
    void rotateR(detailNode<type>*&cur){
        detailNode<type> *left=cur->l;
        cur->l=left->r;
        left->r=cur;
        cur=left;
    }
    
    void preTraverse(detailNode<type> *cur){
        if(cur==NULL)
            return;
        cout<<cur->data<<" ";
        preTraverse(cur->l);
        preTraverse(cur->r);
    }
    void treeDisp(){
        queue<detailNode<type> *> q;
        q.push(root);
        int layer=0;
        while(!q.empty()){
            detailNode<type> * cur=q.front();
            q.pop();
            if(layer!=cur->depth){
                cout<<endl<<endl;
                for(int s=0;s<cur->shift;s++)
                    cout<<" ";
                layer++;
            }
            for(int b=0;b<(cur->width-wid)/2;b++)
                cout<<" ";
            cout<<setw(wid)<<cur->data;//<<"("<<cur->depth<<","<<cur->height<<","<<cur->width<<","<<cur->shift<<") ";
            for(int b=0;b<(cur->width-wid)/2+1;b++)
                cout<<" ";
            if(cur->l!=NULL)
                q.push(cur->l);
            if(cur->r!=NULL)
                q.push(cur->r);
        }
        cout<<endl;
    }
};


void treeSort(tree<int> &T,int * arr, int len){
    for(int i=0;i<len;i++){
        T.insert(T.root,arr[i]);
    }
    T.inTraverse(T.root);
    cout<<endl;
    T.preTraverse(T.root);
    cout<<endl;
    T.breadthFirst();
    cout<<endl;
    cout<<"height: "<<T.height(T.root)<<endl;
}

void print(int * arr, int len){
    cout<<'\t';
    for (int i=0;i<len;i++)
        cout<<arr[i]<<' ';
    cout<<endl<<endl;
}

int max(int a,int b){
    return a>b?a:b;
}
int min(int a,int b){
    return a<b?a:b;
}

int main(int argc,char *argv[]){
    if(argc>3){
        cerr<<"Format: "<<argv[0]<<" [optional] <size of array> <new seed>"<<endl;
        exit(-1);
    }
    int N=10;
    if(argc>1)
        N=atoi(argv[1]);
    if(argc==3)
        srand(time(NULL));
    cout<<N<<" unsorted numbers:"<<endl;
    int *arr=new int[N],*cpy=new int[N];
    for (int i=0;i<N;i++)
        arr[i]=rand()%(2*N)-N;
    print(arr,N);
    
    clock_t	start =clock();
    tree<int> T;
    treeSort(T,arr,N);
    
    detailTree<int> DT;
    
    DT.init(T);
       DT.treeDisp();
    DT.balance(DT.root);
    DT.treeDisp();
    cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
    return 0;
}
