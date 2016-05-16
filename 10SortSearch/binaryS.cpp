#include<iostream>
#include<ctime>
using namespace std;
void print(int *keys,double *data,int len){
    for(int i=0;i<len;i++){
        cout<<keys[i]<<"("<<data[i]<<")\t";
    }
    cout<<endl;
}
template <class K,class D>
class node{
public:
    K k;
    D d;
    node * l;
    node * r;
    node(K key=0,D data=0):k(key),d(data),l(NULL),r(NULL){}
    ~node(){}
};
template <class K,class D>
class tree{
public:
    node<K,D> *root;
    tree():root(NULL){}
    ~tree(){}
    void insert(node<K,D> *&cur,K key,D data){
        node<K,D> *n=new node<K,D>(key,data);
        if(!cur){
            cur=n;
            return;}
        if(cur->k>key)
            insert(cur->l,key,data);
        else
            insert(cur->r,key,data);
    }
    void build(K *keys,D *data,int len){
        for(int i=0;i<len;i++)
            insert(root,keys[i],data[i]);
        inTraverse(root,keys,data);
    }
    void inTraverse(node<K,D> *cur,K *&keys,D *&data){
        if(!cur)
            return;
        inTraverse(cur->l,keys,data);
        *keys++=cur->k;*data++=cur->d;
        inTraverse(cur->r,keys,data);
    }
    void find(node<K,D> *cur,K key,int &i){//how to return the idx with tree search??
        if(!cur)
            return ;
        
        
        find(cur->l,key,i);
        
        if(cur->k==key)
            return ;
        i++;
        
        find(cur->r,key,i);
    }
};

int binaryS(int *keys,int key,int beg,int end){
    if (beg>end)
        return -1;
    int mid=beg+(end-beg)/2;
    if(keys[mid]==key)
        return mid;
    if(keys[mid]<key)
        return binaryS(keys,key,mid+1,end);
    else
        return binaryS(keys,key,beg,mid-1);
}

int triaryS(int *keys,int key,int beg,int end){
    if(beg>end)
        return -1;
    int one=beg+(end-beg)/3,two=beg+(end-beg)*2/3;
    if(keys[one]==key)
        return one;
    if(keys[two]==key)
        return two;
    if(keys[one]>key)
        return triaryS(keys,key,beg,one-1);
    else if(keys[two]<key)
        return triaryS(keys,key,two+1,end);
    else
        return triaryS(keys,key,one+1,two-1);
    
}

int main(int argc,char *argv[])
{
 	if(argc!= 3 ){cerr<<"Format: "<<argv[0]<<" < N > < search key> "<<endl;exit(-1);}
	srand(time(NULL));
 	clock_t start;
    int len=atoi(argv[1]);
    int key=atof(argv[2]);
    int *keys=new int [len];
    double *data=new double [len];
    for(int i=0;i<len;i++){
        keys[i]=rand()%(5*len)-len;
        data[i]=(rand()%(5*len)-len)/2.0;
    }
    print(keys,data,len);
    
    tree<int,double> T;
    start=clock();
    T.build(keys,data,len);
    cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
    print(keys,data,len);
    cout<<endl;
    int idx=0;
    T.find(T.root,key,idx);cout<<idx<<endl;

    start=clock();
    cout<<binaryS(keys,key,0,len-1)<<endl;
    cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
    start=clock();
    cout<<triaryS(keys,key,0,len-1)<<endl;
 	cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	return 0;
}
