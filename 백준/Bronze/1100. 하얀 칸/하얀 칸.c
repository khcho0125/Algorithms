#include<stdio.h>

int main()
{
    int result=0;
    char arr;
    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
        {
            scanf("%c", &arr);
            if(arr=='F' && (i+j)%2==0)
            {
                result++;
            }
        }
        getchar();
    }
    printf("%d", result);
    return 0;
}