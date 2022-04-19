#include<stdio.h>

int main()
{
    int get;
    int pp;
    long long int m[101] = { 0, 1, 1, 1 };

    for(int i = 4; i < 101; i++)
    {
        m[i] = m[i - 2] + m[i - 3];
    }
    scanf("%d", &get);
    for(int i = 0; i < get; i++)
    {
        scanf("%d", &pp);
        printf("%lld\n", m[pp]);
    }
    return 0;
}
