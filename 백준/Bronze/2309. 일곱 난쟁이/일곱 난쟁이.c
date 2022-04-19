#include<stdio.h>

int main()
{
    int num[9];
    int sum = 0;
    int find;
    int temp;
    for(int i = 0; i < 9; i++)
    {
        scanf("%d", &num[i]);
        sum += num[i];
    }
    find = sum - 100;
    for(int i = 0; i < 9; i++)
    {
        for(int j = i + 1; j < 9; j++)
        {
            if(num[i] + num[j] == find)
            {
                num[i] = 0;
                num[j] = 0;
                i = 9;
            }
        }
    }
    for(int i = 0; i < 9; i++)
    {
        for(int j = i + 1; j < 9; j++)
        {
            
            if(num[i] > num[j])
            {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    for(int i = 2; i < 9; i++)
    {
        printf("%d\n", num[i]);
    }
}