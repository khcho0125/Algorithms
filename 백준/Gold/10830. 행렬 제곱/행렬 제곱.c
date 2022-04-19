#include <stdio.h>
#include <stdlib.h>

#define MOD 1000
#define ll long long

typedef struct Matrix
{
    ll arr[5][5];
} X;

X *operator(X *a, X *b, ll N)
{
    X *temp = (X *)malloc(sizeof(X));
    for (int n = 0; n < N; n++)
    {
        for (int i = 0; i < N; i++)
        {
            temp->arr[n][i] = 0;
            for (int j = 0; j < N; j++)
            {
                temp->arr[n][i] += a->arr[n][j] * b->arr[j][i];
            }
            temp->arr[n][i] %= MOD;
        }
    }
    return temp;
}

X *update(ll cnt, X *fib, ll N)
{
    if (cnt == 1)
    {
        return fib;
    }
    if (cnt % 2 == 0)
    {
        X *temp = (X *)malloc(sizeof(X));
        temp = update(cnt / 2, fib, N);
        return operator(temp, temp, N);
    }
    return operator(update(cnt - 1, fib, N), fib, N);
}

int main()
{
    X *fib = (X *)malloc(sizeof(X));
    ll N, M;
    scanf("%lld %lld", &N, &M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%lld", &fib->arr[i][j]);
        }
    }
    fib = update(M, fib, N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%lld ", fib->arr[i][j] % MOD);
        }
        printf("\n");
    }
}