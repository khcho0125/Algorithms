#include<stdio.h>

char num[1000000];
int result[400000];

int main()
{
    int i = 0;
    int sum = 1;
    int upper = 1;
    int len = 0;
    scanf("%s", num);
    while(num[i])
    {
        i++;
        len++;
    }
    for(i = 0; i < len; i++)
    {
        result[upper - 1] += (num[len - 1 - i] - '0') * sum;
        sum += sum;
        if(sum > 4)
        {
            sum = 1;
            upper++;
        }
    }
    if(len % 3 == 0)
    {
        upper--;
    }
    for(i = 0; i < upper; i++)
    {
        printf("%d", result[upper - i - 1]);
    }
}