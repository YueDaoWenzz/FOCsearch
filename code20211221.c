#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define offsetof(TYPE,MEMBER) ((size_t)&(((TYPE *)0)->MEMBER)) //计算结构体中某一成员的偏移
#define container_of(ptr,type,member) (\
    { \
        typeof(((type *)0)->member) * _mtr = ptr; \
        (type*)((char*)_mtr - offsetof(type,member));\
    } \ 
)
//计算结构体的首地址
 typedef struct
{
    unsigned long e;
    char a;
    int b;
    double c;
}TestType;
 int main(void)
 {
     printf("TestType->e的地址为%p\n",&((TestType *)0)->e);
     printf("TestType->a的地址为%p\n",&((TestType *)0)->a);
     printf("TestType->b的地址为%p\n",&((TestType *)0)->b);
     printf("TestType->c的地址为%p\n",&((TestType *)0)->c);
     TestType TestData;
     printf("TestData的地址为%p\n",&TestData);
     printf("TestData的地址为%p\n",container_of(&TestData.c,TestType,c));
     getchar();
     return 0;
 }