#include<iostream>
#include<ctime>
#include<stack>
using namespace std;
int priority(char opr){
    switch(opr){
        case '+':return 1;
        case '-':return 1;
        case '*':return 2;
        case '/':return 2;
        case '#':return 0;
    }
    return -1;
}

int calc(int a,int b,char o){
    switch(o){
        case '+':return a+b;
        case '-':return a-b;
        case '*':return a*b;
        case '/':return a/b;
    }
    return 0;
}

void parse(char * expr){
    stack<int> nb;
    stack<char> op;
    while(*expr){
        char number[10]={'\0'};int i=0;char opr;
        while(*expr-'0'>=0&&*expr-'0'<=9)
            number[i++]=*expr++;
        int num=atoi(number);
        cout<<num;
        nb.push(num);
        if(*expr)
            opr=*expr++;
        else
            opr='#';
        if(op.empty()||priority(op.top())<priority(opr))
            op.push(opr);
        else{
            while(!op.empty()&&priority(op.top())>=priority(opr)){
                int right=nb.top();nb.pop();
                int left=nb.top();nb.pop();
                char o=op.top();op.pop();
                int result=calc(left,right,o);
                cout<<"\t"<<left<<" "<<o<<" "<<right<<" = "<<result<<endl;
                nb.push(result);
            }
            op.push(opr);
        }
        cout<<opr<<endl;
    }
}

int main(int argc,char *argv[])
{
 	if(argc!= 1 ){cerr<<"Format: "<<argv[0]<<" < > "<<endl;exit(-1);}
	srand(time(NULL));
 	clock_t start=clock();

    char expression[50]="20-6-7*8/2+5";
    cout<<expression<<" = "<<20-6-7*8/2+5<<endl<<endl;
    parse (expression);
    cout<<endl;
 	cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	return 0;
}
