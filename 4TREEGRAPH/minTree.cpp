#include"treeNode.h"
#include<ctime>
int main()
{
	srand(time(NULL));
 int *arr=new int[20];
 for(int i=0;i<20;i++)
 	arr[i]=rand()%20-10;
 tree<int> T;
 T.root=T.buildFromArray(arr,0,19);
 T.print(T.root);
}
