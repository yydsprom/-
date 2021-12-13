#include<stdio.h>
int erjinzhi(char *s);
int main()
{
    char s[101];
    scanf("%s",s);
    int n=erjinzhi(s);
    printf("%d\n",n);
    return 0;
}
int erjinzhi(char *s)
{
    int sum=0;
    while(*s)
    {
        sum*=2;//sum*2写前面否则会多计算最后一位而结果大一倍
        sum+=*s++-'0';
    }
    return sum;
}