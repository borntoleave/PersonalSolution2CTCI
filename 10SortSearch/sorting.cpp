#include<iostream>
#include<ctime>
#include<queue>
#include<map>
#include<iomanip>
using namespace std;
void swap(int &a,int &b);
void arrCpy(int *a,int *b,int len);
void print(int * arr, int len);

void bubbleSort		(int *arr, int len);
void insersionSort	(int *arr, int len);
void selectionSort	(int *arr, int len);
void bucketSort		(int *arr, int len);
void treeSort		(int *arr, int len);
void mapSort		(int *arr, int len);
void recSort		(int *arr, int from,int end);
void heapSort		(int *arr, int len);
	void maxHeapify	(int *arr, int start, int end);
void quickSort		(int *arr, int begin, int end);
void mergeSort		(int *arr, int begin, int end);
void biRadixSort	(int *arr, int len, int depth);//watch for negative number
void RadixSort		(int *arr, int len, int depth);
//to be finished
void cocktailSort	();
void combSort		();

int main(int argc,char *argv[])
{
	if(argc!=2){
		cerr<<"Format: "<<argv[0]<<" <size of array>"<<endl;
		exit(-1);
	}
	int N=atoi(argv[1]);
 	srand(time(NULL));
 	cout<<N<<" unsorted numbers:"<<endl;
 	int *arr=new int[N],*cpy=new int[N];
 	for (int i=0;i<N;i++)
 		arr[i]=rand()%(2*N)-N;
 	print(arr,N);
 
 	clock_t start;
 	//bubbleSort
 	arrCpy(cpy,arr,N);cout<<"BubbleSort:\t";start=clock();
 	bubbleSort(cpy, N);
 	cout<<setw(8)<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	print(cpy,N);

 	//insersionSort
 	arrCpy(cpy,arr,N);cout<<"InsersionSort:\t";start=clock();
 	insersionSort(cpy, N);
 	cout<<setw(8)<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	print(cpy,N);

 	//selectionSort
 	arrCpy(cpy,arr,N);cout<<"SelectionSort:\t";start=clock();
 	selectionSort(cpy, N);
 	cout<<setw(8)<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	//print(cpy,N);
 
 	//quickSort
 	arrCpy(cpy,arr,N);cout<<"QuickSort:\t";start=clock();
 	quickSort(cpy, 0, N-1);
 	cout<<setw(8)<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	//print(cpy,N);
 
 	//mergeSort
 	arrCpy(cpy,arr,N);cout<<"MergeSort:\t";start=clock();
 	mergeSort(cpy, 0, N-1);
 	cout<<setw(8)<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	//print(cpy,N);

 	//heapSort
 	arrCpy(cpy,arr,N);cout<<"HeapSort:\t";start=clock();
 	heapSort(cpy, N);
 	cout<<setw(8)<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	//print(cpy,N);

 	//biRadixSort
 	arrCpy(cpy,arr,N);cout<<"BiRadixSort:\t";start=clock();
 	biRadixSort(cpy,N,0);
 	cout<<setw(8)<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	//print(cpy,N);

 	//RadixSort
 	//arrCpy(cpy,arr,N);cout<<"RadixSort:\t";start=clock();
 	//RadixSort(cpy,N,0);
 	//cout<<setw(8)<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	//print(cpy,N);

	//bucketSort
  	arrCpy(cpy,arr,N);cout<<"BucketSort:\t";start=clock();
 	bucketSort(cpy,N);
 	cout<<setw(8)<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	//print(cpy,N);

	//treeSort
  	arrCpy(cpy,arr,N);cout<<"TreeSort:\t";start=clock();
 	treeSort(cpy,N);
 	cout<<setw(8)<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	//print(cpy,N);

 	//mapSort
  	arrCpy(cpy,arr,N);cout<<"MapSort:\t";start=clock();
 	mapSort(cpy,N);
 	cout<<setw(8)<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	//print(cpy,N);

 	//arrCpy(cpy,arr,N);cout<<"RecursiveSort:\t";start=clock();
 	//recSort(cpy,0,N);
 	
 	delete[] arr;
 	delete[] cpy;
}

void swap(int &a,int &b){
 	int temp=a;
 	a=b;
 	b=temp;
}

void arrCpy(int *a,int *b,int len){
 	for (int i=0;i<len;i++)
 		a[i]=b[i];
}

void print(int * arr, int len){
	cout<<'\t';
 	for (int i=0;i<len;i++)
 		cout<<arr[i]<<' ';
 	cout<<endl<<endl;
}

void bubbleSort(int * arr, int len){
 	for(int i=0;i<len;i++)
 		for(int j=i+1;j<len;j++)
 			if(arr[i]>arr[j])
 				swap(arr[i],arr[j]);
}

void insersionSort(int * arr, int len){
    for(int i=1;i<len;i++){
        int temp=arr[i];
        int j;
        for(j=i-1;j>=0&&arr[j]>temp;j--)
            arr[j+1]=arr[j];
        arr[j+1]=temp;
    }
}

void selectionSort(int * arr, int len){
 	for(int i=0;i<len;i++){
 		int min=i;
 		for(int j=i+1;j<len;j++)
 			if(arr[j]<arr[min])
 				min=j;
 		swap(arr[i],arr[min]);
	}
}

void quickSort(int * arr, int begin, int end){
 	if(begin>=end)
 		return;
 	int left=begin,right=end;
 	while(left+1<=right){
 		if(arr[left+1]<arr[left]){
 			swap(arr[left+1],arr[left++]);
 		}
 		else {
 			swap(arr[left+1],arr[right--]);
 		}
 	}
 	quickSort(arr,begin,left-1);
 	quickSort(arr,left+1,end);
}

void mergeSort(int * arr, int begin, int end){//fails at large N
 	//print(arr,end-begin+1);
 	if(begin>=end)
 		return;
 	int mid=begin+(end-begin)/2;
 	mergeSort(arr,begin,mid);
 	mergeSort(arr,mid+1,end);
 	int p1=begin,p2=mid+1,current=0,* sorted=new int [end-begin+1]();
 	while(p1<=mid&&p2<=end)
		sorted[current++]= arr[p1]<arr[p2]?arr[p1++]:arr[p2++];
 	while(p1<=mid)
 		sorted[current++]=arr[p1++];
 	while(p2<=end)
 		sorted[current++]=arr[p2++];
 	for(int i=0;i<end-begin+1;i++)
 		arr[i+begin]=sorted[i];
 	delete[] sorted;
}

void maxHeapify(int * arr, int start, int end){
 	int dad=start, son=start*2+1;
 	while(son<end){
		if(son+1<end && arr[son]<arr[son+1])
			son++;
		if(arr[dad]<=arr[son]){
			swap(arr[dad],arr[son]);
			dad=son;
			son=dad*2+1;
		}
		else return;
 	}
}

void heapSort(int * arr, int len){
 	for(int i=len/2;i>=0;i--){
 		maxHeapify(arr,i,len);
 		//print(arr,len);
 	}
 		//cout<<endl;
 	for(int i=len-1;i>0;i--){
 		swap(arr[0],arr[i]);
 		maxHeapify(arr,0,i);
 		//print(arr,len);
 	}
}

void biRadixSort(int *arr,int len,int depth){
	queue<int> q[4];
	int goOn=0,offset=0;
	for(int i=0;i<len;i++){
		int v=arr[i];
		if(v<0){
			v=-v;
			offset=0;
			}
		else
			offset=2;
		q[offset+((v&(1<<depth))!=0)].push(v);
		goOn|=(v>>(depth+1));//find the max depth
	}
	int n=0;
	for(int k=1;k>=0;k--)
		while(!q[k].empty()){			
			arr[n++]=-q[k].front();
			q[k].pop();
		}
	for(int k=2;k<4;k++)
			while(!q[k].empty()){			
			arr[n++]=q[k].front();
			q[k].pop();
		}		
	if(goOn)
		biRadixSort(arr,len,depth+1);
}
/*
void RadixSort(int *arr, int len, int depth){
	int min=arr[0],max=arr[0];
	for(int i=0;i<len;i++){
		if(arr[i]<min)
			min=arr[i];
		if(arr[i]>max)
			max=arr[i];
	}
	int depth=0;max=max-min+1;
	while(max){
		max/=10;
		depth++;
	}
	unsigned *shift=new unsigned [len];
	for(int i=0;i<len;i++)
		
	queue<int> radix[10];
	for(int d=0;d<depth;d++){
		for(int i=0;i<len;i++){
			shift[i]=arr[i]-min;
			radix[shift[i]%pow(10,depth)].push(arr[i]);
			shift[i]/=10;
		}
		for(int r=0;r<10;r++)
			while(!radix[r].empty()){
				*arr++=shift[radix[r].front()];
				radix[r].pop();
			}
	}	
}*/
/*
void recSort(int *arr,int from,int end){//wrong
	if(end<from)
		return;
	for(int i=0;i<end;i++)
		if(arr[i]==100000)
			continue;
		else if(arr[i]<arr[from]){
			recSort(arr,i,end);
			cout<<arr[from]<<" ";
			arr[from]=100000;
			}
		recSort(arr,from+1,end);
}*/

void bucketSort(int *arr,int len){
	int min=arr[0],max=arr[0];
	for(int i=0;i<len;i++){
		if(arr[i]<min)
			min=arr[i];
		if(arr[i]>max)
			max=arr[i];
	}
	unsigned range=max-min+1;
	unsigned * bucket=new unsigned[range]();
	for(int i=0;i<len;i++)
		bucket[arr[i]-min]++;
	for(int i=0;i<range;i++)
		for(int j=0;j<bucket[i];j++)
			*arr++=i+min;
	delete[]bucket;
}

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
		
		void traverse(treeNode<type> *cur,int *&arr){
			if(cur==NULL)
				return;
			traverse(cur->l,arr);
			*arr++=cur->d;
			traverse(cur->r,arr);
		}
};

void treeSort(int * arr, int len){
	tree<int> T;
	for(int i=0;i<len;i++){
		T.insert(T.root,arr[i]);
		}
	T.traverse(T.root,arr);
}

void mapSort	(int *arr, int len){
	map<int,int> bucket;
	for(int i=0;i<len;i++){
		if(bucket.find(arr[i])==bucket.end())
			bucket.insert(make_pair(arr[i],1));
		else
			bucket[arr[i]]++;
	}
	for(map<int,int>::iterator it=bucket.begin();it!=bucket.end();it++)
		for(int i=0;i<it->second;i++)
			*arr++=it->first;
}

