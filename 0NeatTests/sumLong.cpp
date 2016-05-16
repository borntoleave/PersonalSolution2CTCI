#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#define RANGE_MIN -20
#define RANGE_MAX 20
using namespace std;

// * Complete the function below.

int sumOfIntegers(vector < int > arr) {
	int sum=0;
	cout<<"The input: \t";
    for(int i=0;i<arr.size();i++){
    		cout<<arr[i]<<' ';
    		sum+=arr[i];
    		}
    	cout<<endl<<"correct sum = "<<sum<<endl;

	sum=0;
	int heap=1;
	for(int i=0;i<arr.size();i++){
		if((i+heap)<arr.size()&&((sum+arr[i])>RANGE_MAX||(sum+arr[i]<RANGE_MIN))){
			int temp=arr[i];
			arr[i]=arr[i+heap];
			arr[i+heap]=temp;
			heap++;
			i--;			
			}
		else	{
			sum+=arr[i];
			heap=1;
			}
		if(sum>RANGE_MAX||sum<RANGE_MIN) {
        		cerr<<"Error!"<<endl;
            }
		}
		cout<<"jump method = "<<sum<<endl;
		
    
	for(int i=0;i<arr.size();i++)
		for(int j=i+1;j<arr.size();j++)
			if(arr[i]>arr[j]){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
	cout<<"after sorting : ";
	for(int i=0;i<arr.size();i++){
    		cout<<arr[i]<<' ';
    		}
    	cout<<endl;
    sum=0;
    for(int i=0;i<arr.size()/2;i++){
        
            sum+=arr[i];
            sum+=arr[arr.size()-i-1];
            if(sum>RANGE_MAX||sum<RANGE_MIN) {
        		cerr<<"Error!"<<endl;
            }
            }
    
    if(arr.size()%2)
    		sum+=arr[arr.size()/2+1];
    		cout<<"first and last = "<<sum<<endl;

    
    int beg=0,end=arr.size()-1;
    sum=0;
    while(beg<end){
		while(sum+arr[beg]>=RANGE_MIN){
			sum+=arr[beg++];
			if(sum>RANGE_MAX||sum<RANGE_MIN) {
        		cerr<<"Error!"<<endl;
            }
			if(beg>end)
				break;
			}
		while(sum+arr[end]<=RANGE_MAX){
			sum+=arr[end--];
			if(sum>RANGE_MAX||sum<RANGE_MIN) {
        		cerr<<"Error!"<<endl;
            }
			if(beg>end)
				break;
			}
    		}
    	cout<<"xinfu sum= "<<sum<<endl;
    		

    		
    return sum;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    int _arr_size;
	srand(time(NULL));
	cout<<20<<endl;
	for(int i=0;i<20;i++)
		cout<<rand()%20-10<<endl;
	
    
    cin >> _arr_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _arr;
    int _arr_item;
    for(int _arr_i=0; _arr_i<_arr_size; _arr_i++) {
        cin >> _arr_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _arr.push_back(_arr_item);
    }
    
    res = sumOfIntegers(_arr);
    
    fout << res;
    
    fout.close();
    return 0;
}
