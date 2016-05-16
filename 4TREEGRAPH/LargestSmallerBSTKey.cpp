#include<iostream>
#include<ctime>
using namespace std;

template<class Type>
class node{
public:
    Type data;
    node * left;
    node * right;
    node(Type d):data(d),left(NULL),right(NULL){}
    ~node(){}
    void insert(node * &cur,Type d){
        if(cur==NULL){
            cur=new node(d);
            return;
        }
        if(cur->data >d)
            insert(cur->left,d);
        else
            insert(cur->right,d);
    }
    }
    
    node * build(int *arr, int beg, int end){
        if(beg>end)
            return NULL;
        int mid=beg+(end-beg)/2;
        node *cur=new node(arr[mid]);
        cur->left=build(arr,beg,mid-1);
        cur->right=build(arr,mid+1,end);
        return cur;
    }
    void inP(node * cur){
        if(cur==NULL)
            return;
        inP(cur->left);
        cout<<cur->data<<" ";
        inP(cur->right);
    }
    void findLargestSmall(node *cur,Type key,Type &cur_min){
        if(cur==NULL)
            return;
        if(cur->data >=key)
            findLargestSmall(cur->left,key,cur_min);
        else{
            cur_min=cur->data;
            findLargestSmall(cur->right,key,cur_min);
        }
    }
};

int main(int argc,char *argv[])
{
 	if(argc!= 1 ){cerr<<"Format: "<<argv[0]<<" < > "<<endl;exit(-1);}
	srand(time(NULL));
 	clock_t start=clock();
    
    node<int> *root=NULL;
    int n=10;
    int *arr=new int [n];
    for(int i=0;i<n;i++){
        arr[i]=rand()%(n*5);
        cout<<arr[i]<<" ";
        root->insert(root,arr[i]);
    }
    cout<<endl;
    root->inP(root);
    cout<<endl;
    int cur_min;
    root->findLargestSmall(root,30,cur_min);
    cout<<cur_min<<endl;
    node<int> *rr=rr->build(arr,0,9);
    rr->inP(rr);

 	cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	return 0;
}
