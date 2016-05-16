#include<iostream>
#include<ctime>
using namespace std;
template<class Type>
class node{
public:
    Type data;
    node * l;
    node * r;
    node(Type d):data(d),l(NULL),r(NULL){}

};
template<class Type>
class tree{
public:
    node<Type> *root;
    tree():root(NULL){}
    
    void insert(Type d){
        node<Type> * n=new node<Type>(d);
        if(root==NULL){
            root=n;
        return;
        }
        node<Type> *cur=root;
        while(cur!=NULL){
            if(cur->data >d)
                if(cur->l==NULL){
                    cur->l=n;
                    return;}
                else
                    cur=cur->l;
            else
                if(cur->r==NULL){
                    cur->r=n;
                    return;
                }
                else
                    cur=cur->r;
        }
    }
    
    void rInsert(node<Type> *&cur,Type d){
        if(cur==NULL){
            cur=new node<Type>(d);
            return;}
        if(cur->data>d)
            rInsert(cur->l,d);
        else
            rInsert(cur->r,d);
    }
    
    
    void inP(node<Type> *cur){
        if(cur==NULL)
            return;
        inP(cur->l);
        cout<<cur->data<<" ";
        inP(cur->r);
    }
};

//------------------
template<class Type>
class nodePos{
public:
    Type *data;
    nodePos<Type> *l;
    nodePos<Type> *r;
    nodePos(){data=NULL;}
    nodePos(Type d){*data=d;}
};
template<class Type>
class treePos{
public:
    nodePos<Type> *root;
    treePos(){root=new nodePos<Type>;}
    void insert(Type d){
        nodePos<Type> *cur=root;
        while(cur->data!=NULL){
            if(*cur->data>d)
                cur=cur->l;
            else
                cur=cur->r;
        }
        cur->data=new int(d);
        cur->l=new nodePos<Type>;
        cur->r=new nodePos<Type>;
    }
    void inP(nodePos<Type>*cur){
        if(cur->data==NULL)
            return;
        inP(cur->l);
        cout<<*cur->data<<" ";
        inP(cur->r);
    }
};



int main(){
    srand(time(NULL));
    tree<int> T;
    treePos<int> tt;

    for(int i=0;i<20;i++){
        int x=rand()%50;
        cout<<x<<" ";
        T.insert(x);
        tt.insert(x);
    }
    cout<<endl;
    T.inP(T.root);
    cout<<endl;
    tt.inP(tt.root);
    cout<<endl;
}