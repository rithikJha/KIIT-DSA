#include<stdio.h>
int main()
{
    //pointers on numbers
    printf("pointer on numbers\n");
    int x = 5;
    int* n = &x; // here n is meant to store the address of x
    printf("%d\n",x);
    *n=65; //it is called dereferencing 
    printf("%d\n",*n);
    printf("%d\n",x);

    //pointer on single dimension arrays
    printf("\n\n");
    printf("pointer on single dimension arrays\n");
    int a[5] ={1,2,3,4,5};
    int* p; //p is meant to store the base address of array(a)
    p=&a[0]; //p=a; 
    printf("%d\n",p);
    printf("%d\n",a);
    *(p+1) = 5; //a[1]=5; it is dereferencing
    printf("%d\n",a[1]); 
    //*(a+i)=a[i]
    //(a+i)=&a[i]

    //pointers on multidimensional array
    printf("\n\n");
    printf("pointer on multi dimension arrays\n");
    int b[2][3] = {{1,2,3},{4,5,6}};
    int (*ptr)[3]=b;
    printf("%d %d\n",*ptr,b);
    printf("%d %d %d %d\n",*(ptr+1),b+1,b[1],&b[1][0]);
    printf("%d %d\n",*ptr+2,&b[0][2]);
    printf("%d %d\n",*ptr+2,&b[0][2]);
    

}