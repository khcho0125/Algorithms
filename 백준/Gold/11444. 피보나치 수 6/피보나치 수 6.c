#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define ll long long

typedef struct Matrix
{
    ll arr[2][2];
} X;

X *operator(X *a, X *b)
{
    X *temp = (X *)malloc(sizeof(X));
    for (int n = 0; n < 2; n++)
    {
        for (int i = 0; i < 2; i++)
        {
            temp->arr[n][i] = 0;
            for (int j = 0; j < 2; j++)
            {
                temp->arr[n][i] += a->arr[n][j] * b->arr[j][i];
            }
            temp->arr[n][i] %= MOD;
        }
    }
    return temp;
}

X *update(ll cnt, X *fib)
{
    if (cnt == 1)
    {
        return fib;
    }
    if (cnt % 2 == 0)
    {
        X *temp = (X *)malloc(sizeof(X));
        temp = update(cnt / 2, fib);
        return operator(temp, temp);
    }
    return operator(update(cnt - 1, fib), fib);
}

int main()
{
    X *fib = (X *)malloc(sizeof(X));
    ll N;
    scanf("%lld", &N);
    fib->arr[0][0] = 1;
    fib->arr[0][1] = 1;
    fib->arr[1][0] = 1;
    fib->arr[1][1] = 0;
    fib = update(N, fib);
    printf("%lld", fib->arr[0][1] % MOD);
}