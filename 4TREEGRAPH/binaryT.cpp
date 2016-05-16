#include<iostream>
using namespace std;
class node
{
 public:
 	int num;
 	int count;
 	node * left;
 	node * right;
 	node(int n):num(n),left((node *)NULL),right((node *)NULL){}
 	~node(){left=(node *)NULL;right=(node *)NULL;num=0;}
};

class tree
{
 public:
  	node *root;
  	tree ():root((node *)NULL){}

  	void insert(int n,node *&current){
		if (current==(node *)NULL)
			current=new node(n);
		else{
			if(n<current->num)
				insert(n,current->left);
			else
				insert(n,current->right);
		}		
  	}

  	node * find(int n,node * current){
  		if(current==(node *)NULL){
  			//cout<<"Not found"<<endl;
  			return (node *)NULL;
  			}
		else if(current->num==n){
			cout<<"found!"<<endl;
			return current;}
		else if (find(n,current->left)!=(node *)NULL)
			return find(n,current->left);
		else
			return find(n,current->right);
  		}

  	void del(node *&current){
  	if(current==(node *)NULL)
  			return;
  		cout<<"one operation"<<endl;
		del(current->left);
		del(current->right);
		
		delete current;//not working here!!
		current=(node *)NULL;
		
  		}
  	
  	void prePrint(node * current){
  		
  		if(current==(node *)NULL)
			{
  			return;}
		cout<<current<<' ';
		cout<<current->num<<endl;
		prePrint(current->left);
		prePrint(current->right);
		}
		
	void inPrint(node * current){
  		if(current==(node *)NULL)
  			return;
		inPrint(current->left);
		cout<<current->num<<' ';
		inPrint(current->right);
		}
		
  	void postPrint(node * current){
  		if(current==(node *)NULL)
  			return;
		postPrint(current->left);
		postPrint(current->right);
		cout<<current->num<<' ';
  		}
 


};

int main()
{
 int arr[8]={4,6,2,1,5,7,3,9};  //    _ 4 _
 								//	2		6
 								//1	 3	  5	  7
 								//				9
 
	tree *T=new tree;
	for(int i=0;i<8;i++)
		T->insert(arr[i],T->root);
	
	//T->insert(4);
	T->prePrint(T->root);cout<<endl;
	T->inPrint(T->root);cout<<endl;
	T->postPrint(T->root);cout<<endl<<endl;
	cout<<T->find(8,T->root)<<endl<<endl;
	cout<<T->find(5,T->root)<<endl<<endl;
	cout<<T->find(9,T->root)<<endl<<endl;
	node * loc=T->find(6,T->root);
	cout<<loc<<endl;
	T->del(loc);
	cout<<"after del: ";
	T->prePrint(T->root);cout<<endl;

}
