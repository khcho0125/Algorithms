#include<stdio.h>

int main()
{
    int result=0, n, ten=0, one=0, com=0;
    scanf("%d", &n);
    one = n % 10;
    ten = n / 10;
    do
    {
        com = ten+one;
        com = com % 10;
        com = com+one*10;
        one = com % 10;
        ten = com / 10;
        result++;
    } while (n!=com);
    printf("%d", result);
    return 0;
}