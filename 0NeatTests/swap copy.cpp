//You can swap only two consecutive elements. You have to show all steps to convert a string into another string (both strings will be anagrams of each other). E.g. GUM to MUG 

//GUM 
//GMU 
//MGU 
//MUG
#include<iostream>
using namespace std;
int main()
{
        char a[] = "ABCD123";
        char b[] = "312DBCA";
        char temp;
        int n = sizeof(b);
        int j, i = 0;
        while(n > i) {
                        j = i;
                        printf("\n%s",a);
                        while(a[j] != b[i]) {
                                j++;
                        }
                        while(j > i) {
                                temp = a[j];
                                a[j] = a[j-1];
                                a[j-1] = temp;
                                printf("\n%s",a);
                                j--;
                        }
                        i++;
                        	printf("\n");
        }
        	printf("\n");
}
