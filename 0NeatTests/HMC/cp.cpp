#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
#define LIST 20
using namespace std;
void train(double *count1,double **count2);
void test(double *count1,double **count2,string method);
double getScoreNaive(string code,double *count1);
double getScoreHMC(string code,double *count1,double **count2);
class pwd
{
public:
	pwd(){
		idx=0;
		code="";
		score=0;
		}
	~pwd(){};
	double getScore(){
		return score;
		}
	void storePwd(int i,string c,double s){
		idx=i;
		code=c;
		score=s;
		}
	void print(){
		cout<<"line: "<<idx<<"\tcode: "<<left<<setw(35)<<code<<"score: "<<score<<endl;
		}
private:
	int idx;
	string code;
	double score;
};

int main(int argc,char *argv[])
{
if (argc!=2){cerr<<"Format: "<<argv[0]<<" <method>"<<endl;exit(-1);}
double *count1=new double [128];
double **count2=new double *[128];
train(count1,count2);
cout<<"------------------------------------\ngetting "<<argv[1]<<" scores..."<<endl;
test(count1,count2,argv[1]);
}

void train(double *count1,double **count2)
{
ifstream train("./train.txt",ios::in);
int total1=0;
int *total2=new int [128];
for(int i=0;i<128;i++)	{
	count1[i]=0;
	total2[i]=0;
	count2[i]=new double [128];
	for(int j=0;j<128;j++)
		count2[i][j]=0.00000001;//avoid -log 0.
	}
while(train.good()){
	string buffer;
	getline(train,buffer);
	for(int i=0;i<buffer.length();i++)	{
		count1[int(buffer[i])]++;//occurance of one symbol X
		total1++;				//total occurance of symbols
		if(i<buffer.length()-1)	{
			count2[int(buffer[i])][int(buffer[i+1])]++;
			total2[int(buffer[i])]++;
			}
		}
	}
for(int i=0;i<128;i++)	{
	count1[i]/=total1;
	for(int j=0;j<128;j++)	{
		if(total2[i])
			count2[i][j]/=total2[i];	
		}
	}
}

void test(double *count1,double **count2,string method)
{
pwd best[LIST],worst[LIST];
int initIdx,line;initIdx=0;line=1;
double score;
ifstream pw("./pw.txt",ios::in);
while(pw.good()){
	string buffer;
	getline(pw,buffer);
	if(buffer=="")
		break;
	if(method=="naive")
		score=getScoreNaive(buffer,count1);
	else if(method=="HMC")
		score=getScoreHMC(buffer,count1,count2);
	else {
		cerr<<"                    @l@"<<endl
			<<"I don't know how... /V>"<<endl
			<<"                    < >"<<endl;
		exit(1);
		}
	if(initIdx<LIST)	{
		best[initIdx].storePwd(line,buffer,score);
		worst[initIdx].storePwd(line,buffer,score);
		initIdx++;
		}
	for(int i=0;i<LIST;i++)
		if(score>best[i].getScore())	{
			best[i].storePwd(line,buffer,score);
			break;}
	for(int i=0;i<LIST;i++)
		if(score<worst[i].getScore())	{
			worst[i].storePwd(line,buffer,score);
			break;}
	line++;
	}
cout<<"* Best LIST ------------"<<endl;
for(int i=0;i<LIST;i++)
	best[i].print();
cout<<"* Worst LIST ------------"<<endl;
for(int i=0;i<LIST;i++)
	worst[i].print();
}

double getScoreNaive(string code,double *count1)
{
double score=0;
for(int i=0;i<code.length();i++)	
	score+=-log10(count1[code[i]]);
return score;
}	

double getScoreHMC(string code,double *count1,double **count2)
{
double score=-log10(count1[code[0]]); 
for(int i=0;i<code.length()-1;i++)	{	
	score+=-log10(count2[int(code[i])][int(code[i+1])]);
	}
return score;
}	
