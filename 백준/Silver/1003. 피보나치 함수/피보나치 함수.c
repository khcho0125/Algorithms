#include <stdio.h>

int one_fibo_arr[41];

int zero_fibo_arr[41];

int zero_fibo(int n)
{
    if (zero_fibo_arr[n] != 0)
    {
        return zero_fibo_arr[n];
    }
    else
    {
        if (n == 0)
        {
            return 1;
        }

        if (n == 1)
        {
            return 0;
        }
        int a = zero_fibo(n - 1);
        zero_fibo_arr[n - 1] = a;
        int b = zero_fibo(n - 2);
        zero_fibo_arr[n - 2] = b;
        return a + b;
    }
}

int one_fibo(int n) {
    if (one_fibo_arr[n] != 0)
    {
        return one_fibo_arr[n];
    }
    else
    {
        if (n == 0)
        {
            return 0;
        }

        if (n == 1)
        {
            return 1;
        }
        int a = one_fibo(n - 1);
        one_fibo_arr[n - 1] = a;
        int b = one_fibo(n - 2);
        one_fibo_arr[n - 2] = b;
        return a + b;
    }
}

int main()
{
    int N, T, i;
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        scanf("%d", &N);
        int zero = zero_fibo(N);
        zero_fibo_arr[N] = zero;
        int one = one_fibo(N);
        one_fibo_arr[N] = one;
        printf("%d %d\n", zero, one);
    }
}