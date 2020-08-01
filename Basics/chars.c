#include<stdio.h>
#include<string.h>
void print1(char a[])
{
    int i=0;
    while(a[i]!='\0')
    {
        printf("%c",a[i]);
        i++;
    }
}
void print2(char *a)
{
    while(*a!='\0')
    {
        printf("%c",*a);
        a++; //incrementing a pointer increments its value by sizeof(datatype of that pointer)
    }
}
int main()
{
    char a[] = "hello there"; //here string is stored in space allocated to the array
    printf("%s\n",a);
    a[2]='y';
    printf("%s\n",a);

    char *a2 = "hello there"; //here string is stored as a compile time constant which cannot be edited
    printf("%s\n",a2); //a2[2]='y' cannot be done here

    char b[5];
    b[0]='h';
    b[1]='e';
    b[2]='l';
    b[3]='l';
    b[4]='\0';
    printf("%s\n",b); 

    char c[3];
    c[0]='h';
    c[1]='e';
    c[2]='l';
    c[3]='p';
    printf("%s\n",c);

    char d[15] = "hello there";
    printf("%s\n",d);

    char e[5] = {'j','o','h','n','\0'};
    printf("%s\n",e);

    char f[] = "testing arguments\n";
    print1(f);
    print2(f);

    return 0;
}