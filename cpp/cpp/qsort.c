#include<stdio.h>
#include<stdlib.h>
int cmp(const void *x,const void* y);
int main()
{
    int s[101],n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&s[i]);
    qsort(s,n,sizeof(int),cmp);
    for(int i=0;i<n;i++)
        printf("%d ",s[i]);
    return 0;
}
int cmp(const void *x,const void* y)
{
    return (*(int*)x-*(int*)y);
}
