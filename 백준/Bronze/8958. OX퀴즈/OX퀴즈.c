#include<stdio.h>

int main()
{
    int n;
    int i = 0;
    int j = 0;
    int result = 0;
    int sum = 0;
    char score[80];
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%s", score);
        while (score[j])
        {
            
            if(score[j] == 'O')
            {
                sum++;
                result += sum;
            }
            if(score[j] == 'X')
            {
                sum = 0;
            }
            j++;
        }
        sum = 0;
        j = 0;
        printf("%d\n", result);
        result = 0;
    }
}