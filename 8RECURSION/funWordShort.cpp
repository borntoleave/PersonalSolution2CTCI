//A string has several characters. you find the reversing sequence and call it a fun word. its score will be its length. try to find two non-overlapping fun words in a given string and calculate the len1*len2. find the best score. 
//example: string "adsaidmmefsfmd"
//					ada  dmfsfmd 
//					 3 *   7	= 21
#include<iostream>
using namespace std;
int max(int a, int b){
 return a>b?a:b;
}

int recursive(char *str,int begin, int end){
 if(begin>end)
 	return 0;
 else if(begin==end){
 	return 1;
 	}
 else{//(begin<end)
 	if(str[begin]==str[end])
 		return 2+recursive(str,begin+1,end-1);
 	else
 		return max(recursive(str,begin+1,end),
 				recursive(str,begin,end-1));
 	}
}

int funScore(char *str){
 int len=strlen(str);
 int m=0,subLen0,subLen1;
 for(int mid=0;mid<len-1;mid++)
 	m = max(m,recursive(str,0,mid)
 		*recursive(str,mid+1,len-1));
 cout<<str<<endl;
 return m;
}

int main(){
 char str[50]="adsaidmmefsfmd";
 cout<<funScore(str)<<endl<<endl;

 char s[50]="axxfdxxcxxbcc";
 cout<<funScore(s)<<endl;
}

