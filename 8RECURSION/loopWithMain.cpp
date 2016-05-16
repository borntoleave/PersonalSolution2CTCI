#include <stdio.h>
#include <stdlib.h>
void f(int j);
void f1(int j);
void f1(int j)
{
	static void (*const ft[3])(int) = { f,f1, exit };
	
    printf("%d\n", j);
    ft[j/10](j + 1);


}

void f(int j)
{
    static void (*const ft[3])(int) = { f,f1, exit };

    printf("%d\n", j);
    ft[j/10](j + 1);
}

int main(int argc, char *argv[])
{
    f(1);
}
