#include<iostream>
#include<string>
#include<list>
using namespace std;
template<class Type>
class treeNode{
 public:
 	Type data;
	treeNode *left;
	treeNode *right;

 	treeNode(Type d=Type(NULL)):data(d){}
 	~treeNode(){}
 	void setD(Type d){data=d;}
	void setL(treeNode *t){left=t;}
	void setR(treeNode *t){right=t;}
};
template<class Type>
class tree{
 public:
 	treeNode<Type> *root;

 	tree(){root= new treeNode<Type>;}
 	~tree(){}
 	treeNode<Type> * getR(){return root;}
	treeNode<Type> * buildFromArray(int * arr,int start,int end){
		if(start>end){
			cout<<"fin"<<endl;
			return NULL;
		}
		int mid=(end+start)/2;
		cout<<mid<<endl;
		treeNode<Type> * cur=new treeNode<Type>(arr[mid]);
		cout<<start<<' '<<mid-1<<"\t"<<mid+1<<' '<<end<<endl;
		cur->left=buildFromArray(arr,start,mid-1);
		cur->right=buildFromArray(arr,mid+1,end);
		return cur;
	}
	void print(treeNode<Type> *cur){
		if(cur!=NULL){
		print(cur->left);
		cout<<cur->data<<" ";
		print(cur->right);
		}
	}
};

