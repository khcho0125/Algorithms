#include<stdio.h>

void change(int n, int from, int by, int to)
{
    if(n > 1){
        change(n - 1, from, to, by);
        printf("%d %d\n", from, to);
        change(n - 1, by, from, to);
    }
    else
    {
        printf("%d %d\n", from, to);
    }
}
int math(int num)
{
    if(num > 1)
    {
        return math(num - 1) * 2 + 1;
    }
    else
    {
        return 1;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", math(n));
    change(n, 1, 2, 3);
    return 0;
}