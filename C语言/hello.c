#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int panduan(int n)  //返回不同数字的个数
{
    int ge = n % 10;
    int shi = n % 100 / 10;
    int bai = n % 1000 / 100;
    int qian = n / 1000;

    int a[10] = { 0 };
    int max = 0;
    a[ge]++;
    a[shi]++;
    a[bai]++;
    a[qian]++;
    for (int i = 0; i < 10; i++)
    {
        if (max < a[i])
            max = a[i];

    }
    if (max == 1)
        return 4;
    if (max == 2)
        return 3;
    if (max == 3)
        return 2;
    if (max == 4)
        return 0;

}



int main()
{
    int year, different;
    scanf_s("%d%d", &year, &different);
    int i;
    int temp;
    int answers;
    for (i = 0;; i++)
    {
        temp = year + i;
        if (panduan(temp) == different)
            answers = i;

    }

    printf("%d %d", i, year + i);
}
