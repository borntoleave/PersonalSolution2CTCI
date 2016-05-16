#include<iostream>
#include<ctime>
using namespace std;
void life() {
    srand(time(NULL));
    int young = 0, old = 1 + rand()% 120;
    while (old-young++) ;
    cout << young ;
    cout << endl ;
}

int main(){
    srand(time(NULL));
    for(int i=0;i<100;i++)
    life();

}