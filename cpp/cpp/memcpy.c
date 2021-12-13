#include<stdio.h>
#include<string.h>
int main()
{
    char s1[44]="hello world!";
    char s2[44];
    char s3[44];
    memcpy(s2,s1,strlen(s1)+1);//将字节长度为stlen(s1)+1的字符串从s2复制到s1
    memcpy(s3,&s2[4],strlen(s2)+1);//将字节长度为strlen(s2)+1的字符串从地址&s2[4]开始复制到s3中
    puts(s1);
    puts(s2);
    puts(s3);
    return 0; 
}