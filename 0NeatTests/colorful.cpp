/*Colorful Number: 
A number can be broken into different sub-sequence parts. Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. And this number is a colorful number, since product of every digit of a sub-sequence are different. That is, 3 2 4 5 (3*2)=6 (2*4)=8 (4*5)=20 (3*2*4)= 24 (2*4*5)= 40 
But 326 is not a colorful number as it generates 3 2 6 (3*2)=6 (2*6)=12. 
You have to write a function that tells if the given number is a colorful number or not.
*/

//Rz Jan 16

#include<iostream>
using namespace std;
int main(int argc, char *argv[])
{
	if(argc!=2) {	
		cerr<<argv[0]<<"<integer>"<<endl;exit(-1);
	}

	int num_len=strlen(argv[1]);
	int *num=new int [num_len];
	for(int i=0;i<num_len;i++) {
		num[i]=argv[1][i]-'0';
	}								//get digits
	int sub_count=(num_len+1)*num_len/2-1;
	int *sub=new int [sub_count];
	int count=0;
	for(int sub_len=0;sub_len<num_len-1;sub_len++)
		for(int i=0;i+sub_len<num_len;i++) {
			int product=num[i];
			//sub[count]=num[i];
			for(int j=1;j<=sub_len;j++)	{
				//sub[count]=sub[count]*10+num[i+j];		//get sub seq
				product*=num[i+j];						//get product of sub seq
			}
			sub[count++]=product;
		}
	for(int i=0;i<sub_count;i++)
		cout<<sub[i]<<endl;
	for(int i=0;i<sub_count;i++)					//check duplicates
		for(int j=i+1;j<sub_count;j++)
			if(sub[i]==sub[j])	{
			cout<<//i<<'\t'<<sub[i]<<'\t'<<j<<'\t'<<sub[j]<<"\t
			"Not colorful!"<<endl;
			exit(0);
			}
	cout<<"Colorful!"<<endl;
			
			
			
	




}
