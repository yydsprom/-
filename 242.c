#include<stdio.h>
#include<string.h>
int isAnagram(char * s, char * t){
    int num1,num2,i;
    num1 = strlen(s);
    num2 = strlen(t);
    if(num1!=num2)
        return 0;
    int sum[26];
    memset(sum,0,26*4);
    for(i = 0;i<num1;i++)
    {
        sum[s[i]-97]++;
        sum[t[i]-97]--;
    }
    for(i=0;i<26;i++)
    {
        if(sum[i]!=0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{  
    printf("%d",isAnagram("anagram","nagaram"));
}