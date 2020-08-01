#include<stdio.h>
#include<stdlib.h>
int sq(int x)
{
    return x*x;
}
int id(int x)
{
    return x;
}
void pon(int x,int (*gen)(int))
{
    printf("\n%d",5*gen(x));
}
int main()
{
    int* p = (int*)malloc(sizeof(int));
    *p=5;
    printf("%d",*p);
    void (*gnc)(int,int (*)(int));
    gnc = pon;
    gnc(6,sq);

}