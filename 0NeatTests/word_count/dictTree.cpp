#include<iostream>
#include<fstream>
#include<string>
#include<cctype>
#define CHAR 26
//#include<map> //I'll write my own dictionary tree
using namespace std;
class node
{
 public:
 	char ch;
 	int count;
 	int end;
 	node ** child;
 	node(){
 		count=0; 	
 		child=NULL;
 		end=0;	
 		//cout<<"Constructor A"<<endl;
 		}
 	~node(){//cout<<"Destructor B"<<endl;
 	}
};

class dicTree:public node
{
 public:
 	node * root; 
 	dicTree(){
 		root=new node;
 		//cout<<"Constructor C"<<endl;
 		}
 	~dicTree(){//cout<<"Destructor D"<<endl;
 	}
 	void insert(string word);
	void traverse(node * current,string pre);
};

void dicTree::insert(string word)
{
 node *current=root;

 int len=word.length();
 for(int i=0;i<len;i++){
	//cout<<word[i]<<' ';
 	if(word[i]=='\0'){//cout<<"break"<<endl;
 		break;}
    current->count++;
    //cout<<current->count<<' ';
 	int idx=int (word[i]-'a');
 	//cout<<word[i]<<idx<<' ';
 	if(current->child==NULL&&i<len){
 		//cout<<"create for "<<word[i]<<endl;;
 		current->child=new node *[CHAR];
 		for(int i=0;i<CHAR;i++){
 			current->child[i]=new node;
 			}
 		}
	if(i==len-1)current->end=1;
 	current=current->child[idx];
 	
 	}
 
}

void dicTree::traverse(node * current,string pre)
{
 char* local;
 for(int i=0;i<CHAR;i++){
 	if(current->child[i]->count){
		pre+=char(i+'a');
		local=&pre.back();
 		traverse(current->child[i],pre);
 		if(current->end){
 			cout<<pre;
 		*local='\0';
 		
 		
 		cout<<endl;}
 		}
 		
 		
 	}
 	
}


string process(string orig)
{
 int len=orig.length();
 for(int i=0;i<len;i++){
 	if(orig[i]>='A'&&orig[i]<='Z')//to lower case
 		orig[i]=orig[i]-('A'-'a');
 	if(ispunct(orig[i]))//remove punctuations
 		orig[i]='\0';
 	}
 return orig;
}

int main(int argc,char * argv[])
{
 if(argc!=2){
 	cerr<<"Format: "<<argv[0]<<" <textfile>"<<endl;exit(-1);}
 ifstream in(argv[1],ios::in);
 if(in.fail()){
 	cerr<<"Cannot open file!"<<endl;exit(-2);}
 dicTree T;
 cout<<"create tree"<<endl;
 
 string buffer;
 int nWord=0;
 
 while(in>>buffer){
 	buffer=process(buffer);
 	T.insert(buffer);
 	nWord++;
	}
 cout<<nWord<<" words: "<<T.root->count<<endl;
 
 T.traverse(T.root,"");

}



