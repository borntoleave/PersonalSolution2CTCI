#include<iostream>
#include<ctime>
#include<vector>
#include<iomanip>
using namespace std;

template<class T>
void swp(T & a,T & b){
    T temp=a;
    a=b;
    b=temp;
}
template<class T>
void quickSort(T *  &arr, int begin, int end){
    if(begin>=end)
        return;
    int left=begin,right=end;
    while(left+1<=right){
        if(arr[left+1]<arr[left]){
            swp(arr[left+1],arr[left++]);
        }
        else {
            swp(arr[left+1],arr[right--]);
        }
    }
    quickSort(arr,begin,left-1);
    quickSort(arr,left+1,end);
}


template<class T>
class heap{
public:
    vector<T> h;
    heap(){};
    void print(){
        for (int i=0;i<h.size();i++)
            cout<<h[i]<<" ";
        cout<<endl;
    }
    void push_back(T num){//push num to the heap without sorting
        h.push_back(num);
    }
    void sort(){//heap sort
        int len=h.size();
        for(int i=len/2;i>=0;i--){
            heapify(i,len);
        }
        for(int i=len-1;i>0;i--){
            swp(h[0],h[i]);
            heapify(0,i);
        }
    }
    void heapify(int start,int end){
        int p=start,c=start*2+1;
        while(c<end){
            if(c+1<end && h[c]>h[c+1])//always use the min son
                c++;
            if(h[p]>=h[c]){
                swp(h[p],h[c]);
                p=c;
                c=p*2+1;
            }
            else return;
        }
    }
    void add(T num,int heapSize){//update the heap of n maximum numbers
        if(h.size()<heapSize){                  //ALGORITHM PART
            h.push_back(num);                   //ALGORITHM PART
            heapify(0,h.size());
        }                                       //ALGORITHM PART
        if(h[0]<num){                           //ALGORITHM PART
            h[0]=num;
            heapify(0,h.size());                //ALGORITHM PART
        }                                       //ALGORITHM PART
    }
};


int main(int argc, char *argv[]){
    if(argc!=3){
        cerr<<argv[0]<<" <nNum> <heapSize>"<<endl;
        exit(-1);
    }
    srand(time(NULL));
    clock_t start;
    heap<double> h1,h2;//sort h1 for checking result, h2 is the actual heap used
    int nNum=atoi(argv[1]),heapSize=atoi(argv[2]);
    double *arr=new double [nNum];
    cout<<"Unsorted:\t";
    for(int i=0;i<nNum;i++){
        arr[i]=rand()%(nNum*10)/10.0;
        //cout<<arr[i]<<" ";
    }
    cout<<endl<<"Quick sort:\t";
    start=clock();
    quickSort(arr,0,nNum-1);
    //for(int i=0;i<nNum;i++)
    //    cout<<arr[i]<<" ";
    //cout<<endl;
    cout<<setw(8)<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
    
    cout<<"Heap sort:\t";
    start=clock();
    for(int i=0;i<nNum;i++)
        h1.push_back(arr[i]);
    h1.sort();
    //h1.print();//show the sorting result for checking
    cout<<setw(8)<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
    
    cout<<"This algorithm:\t";
    start=clock();                      //ALGORITHM PART
    for(int i=0;i<nNum;i++)             //ALGORITHM PART
        h2.add(arr[i],heapSize);        //ALGORITHM PART
    //h2.print();//show the maximum numbers
    cout<<setw(8)<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
}
