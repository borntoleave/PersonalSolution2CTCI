#include<iostream>
#include<ctime>
using namespace std;

int randB(int r){
    return rand()%100>r?1:0; //r% to be 0;
}

int randT(){
    int s=randB(70);
    while(1){
        int t=randB(70);
        if(!s&&t)
            return 0;
        else if(s&&!t)
            return 1;
        else
            s=t;
    }
}

int randT1(){
    int s=randB(70);
    int c=0;
    while(1){
        int t=randB(70);
        if(s==t){
            c++;
            //s=t;
        }
        else break;
    }
    return c&1;
}

int randT2(){
    while(1){
        if(!randB(70)&&randB(70))
            return 0;
        else if(randB(70)&&!randB(70))//the randB pair is different from the last one!
            return 1;
    }
}

int randT3(){
    
    while(1){
        int s=randB(70);
        int t=randB(70);
        if(s&&!t)
            return 1;
        else if(!s&&t)
            return 0;
        else continue;
    }
}

int main(int argc,char *argv[])
{
 	if(argc!= 1 ){cerr<<"Format: "<<argv[0]<<" < > "<<endl;exit(-1);}
	srand(time(NULL));
 	clock_t start=clock();
    int countB[2]={0},count1[2]={0},count2[2]={0},count3[2]={0};
    for(int i=0;i<10000000;i++){
        countB[randB(70)]++;
        count1[randT1()]++;
        count2[randT2()]++;
        count3[randT3()]++;
    }
    cout<<countB[0]<<" "<<countB[1]<<endl;
    cout<<count1[0]<<" "<<count1[1]<<endl;
    cout<<count2[0]<<" "<<count2[1]<<endl;
    cout<<count3[0]<<" "<<count3[1]<<endl;
 	cout<<(clock()-start)/(double)(CLOCKS_PER_SEC / 1000)<<" ms."<<endl;
 	return 0;
}
