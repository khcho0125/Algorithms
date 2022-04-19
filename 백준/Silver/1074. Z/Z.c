#include <stdio.h>

unsigned long long idx = 0;
int R, C;

void func(int N, int r, int c)
{

    if (N == 0)
    {
        printf("%d", idx);
        return;
    }
    unsigned long long t = 1;
    for (int i = 0; i < N - 1; i++, t *= 2);

    if (r + t > R && c + t > C)
    {
        func(N - 1, r, c);
    }
    else if (r + t <= R && c + t > C)
    {
        idx += t*t;
        func(N - 1, r + t, c);
    }
    else if (r + t > R && c + t <= C)
    {
        idx += t*t*2;
        func(N - 1, r, c + t);
    }
    else
    {
        idx += t*t*3;
        func(N - 1, r + t, c + t);
    }
}

int main()
{
    int N;
    scanf("%d %d %d", &N, &C, &R);
    func(N, 0, 0);
}