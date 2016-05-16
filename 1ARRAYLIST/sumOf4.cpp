//Given an array of numbers arr and a number s. Find 4 different numbers in are that sum up to s.
//try ./a.out 10 1 2 3 4 and ./a.out 10 1 2 3 4.5

#include<iostream>
#include<ctime>
#include<map>
#include<iterator>
#define N 100
using namespace std;
bool diff(double indv[4]){
    for(int i=0;i<4;i++)
        for(int j=i+1;j<4;j++)
            if(indv[i]==indv[j])
                return false;
    return true;
}

int main(int argc,char *argv[])
{
    if(argc!= 6 ){cerr<<"Format: "<<argv[0]<<" <Sum n1 n2 n3 n4> "<<endl;exit(-1);}
    srand(time(NULL));
    clock_t start=clock();
    double *arr=new double[N],sum=atof(argv[1]);
    map<double,int> h;
    for(int i=0;i<4;i++){
        arr[i]=atof(argv[i+2]);
        h.insert(make_pair(arr[i],1));
    }
    for(int i=4;i<N;i++){
        arr[i]=(rand()%10000-2000)/100.0;
        if(h.find(arr[i])==h.end()){
            h.insert(make_pair(arr[i],1));
            cout<<arr[i]<<" ";
        }
        else {
            i--;
            continue;
        }
    }
    cout<<endl;
    for(map<double,int>::iterator it=h.begin();it!=h.end();it++){
        cout<<it->first<<" ";
    }
    cout<<endl<<endl;
    // int count=0;
    map<double,int>sub;
    for(map<double,int>::iterator it1=h.begin();it1!=h.end();it1++)
        for(map<double,int>::iterator it2=next(it1,1);it2!=h.end();it2++){
            int sb=it1->first+it2->first;
            if(sub.find(sb)==sub.end())
                sub.insert(make_pair(sb,1));
            else
                sub[sb]++;
            //        count++;
        }
    //cout<<count<<endl;//4950 = 100*99/2. correct
    /* for(map<double,int>::iterator it=h.begin();it!=h.end();it++)
     cout<<"<\t"<<it->first<<",\t"<<it->second<<">"<<endl;*/
    
    
    for(map<double,int>::iterator it=sub.begin();it!=sub.end();it++){
        double *subSum=NULL;
        if(sub.find(sum-it->first)!=sub.end()){//found sub1+sub2=sum
            if(sum - it->first == it->first&&sub[it->first]==2){
                subSum=new double[2];
                subSum[0]=subSum[1]=it->first;
            }
            else{
                subSum=new double[2];
                subSum[0]=it->first;
                subSum[1]=sum-it->first;
            }
            
            double indv[4]={0};int flag=1;
            for(int s=0;s<2;s++){
                for(int i=0;i<N;i++){
                    if(h.find(subSum[s]-arr[i])!=h.end()){
                        indv[s*2]=arr[i];indv[s*2+1]=subSum[s]-arr[i];
                    }
                }
                if(flag==0)
                    break;
            }
            if(flag&&diff(indv)){//check identical
                cout<<"  "<<indv[0]<<" + "<<indv[1]<<" + "<<indv[2]<<" + "<<indv[3]<<endl;
                cout<<"= "<<subSum[0]<<" + "<<subSum[1]<<" = "<<sum<<endl;
                break;
            }
        }
    }
    
    
    cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
    return 0;
}
