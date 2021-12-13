#include<stdio.h>
#include<time.h>
void delay(double second);
int main(void)
{
    double input;
    printf("enter a second to delay:");
    scanf("%lf",&input);
    delay(input);
}
void delay(double second)
{
    clock_t start=clock();
    printf("now let's test %f second delay \n",second);
    clock_t now=clock();
    while(((double)(now-start))/CLOCKS_PER_SEC<second)
    {
        now=clock();
        printf("you delay %f second .\n",((double)(now-start)/CLOCKS_PER_SEC));
    }
}