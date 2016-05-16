//A string has several characters. you find the reversing sequence and call it a fun word. its score will be its length. try to find two non-overlapping fun words in a given string and calculate the len1*len2. find the best score. 
//example: string "adsaidmmefsfmd"
//					ada  dmfsfmd 
//					 3 *   7	= 21
#include<iostream>
using namespace std;
int max(int a, int b){
 return a>b?a:b;
}

int recursive(char *str,char *sub,int begin, int end){
 if(begin>end)
 	return 0;
 else if(begin==end){
 	sub[begin]='1';
 	return 1;
 	}
 else{//(begin<end)
 	if(str[begin]==str[end]){
 		//cout<<str[begin]<<str[end]<<'\t';
 		sub[begin]=sub[end]='1';
 		return 2+recursive(str,sub,begin+1,end-1);
 		}
 	else{
 		char *localSub1=new char[strlen(str)],
 			*localSub2=new char[strlen(str)];
 		for(int i=0;i<strlen(str);i++){
 			localSub1[i]=sub[i];
 			localSub2[i]=sub[i];
 			}
 		int s1=recursive(str,localSub1,begin+1,end);
 		int s2=recursive(str,localSub2,begin,end-1);
 		if(s1>s2){
 			for(int i=0;i<strlen(str);i++)
				sub[i]=localSub1[i];
			return s1;
 			}		
 		else{
 			for(int i=0;i<strlen(str);i++)
				sub[i]=localSub2[i];
			return s2;
 			}	
 		}
 	}
}

int funScore(char *str){
 int len=strlen(str);
 int *maxSubLen=new int[2];
 int m=0,subLen0,subLen1;
 char *sub=new char[len];
 char *localSub=new char[len];

 maxSubLen[0]=maxSubLen[1]=0;
 for(int mid=0;mid<len-1;mid++){
 	for(int i=0;i<len;i++)
 		localSub[i]='0';
 	subLen0=recursive(str,localSub,0,mid);
 	subLen1=recursive(str,localSub,mid+1,len-1);
 	if(subLen0*subLen1>m){
 		m=subLen0*subLen1;	
 		maxSubLen[0]=subLen0;
 		maxSubLen[1]=subLen1;
 		for(int i=0;i<len;i++)
 			sub[i]=localSub[i];
 		}
 	}
 cout<<str<<endl
 	<<sub<<endl;
 int count=0;
 for(int i=0;i<len;i++)
 	if(sub[i]!='0'){
 		cout<<str[i];
		count++;
		if(count==maxSubLen[0])
			cout<<' ';//print seperation of words
 		}
 cout<<endl
 	<<maxSubLen[0]<<" x "<<maxSubLen[1]<<" = "<<maxSubLen[0]*maxSubLen[1]<<endl;
 return m;
}

int main(){
 char str[50]="adsaidmmefsfmd";
 cout<<funScore(str)<<endl<<endl;

 char s[50]="axxfdxxcxxbcc";
 cout<<funScore(s)<<endl;
}


