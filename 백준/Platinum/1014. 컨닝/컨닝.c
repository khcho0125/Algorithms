#include <stdio.h>
#include <string.h>

#define ll long long
#define max(a, b) ((a) > (b) ? a : b)

ll map[10] = {
    0,
};
int dp[1 << 10][10];
int M, N;


int check(int before, int next) {
    int cnt = 0;
    int one, two;
    for(int i = 0; i < M; i++) {
        if(next & 1 << i) {
            one = 1 << (i + 1);
            two = 1 << (i - 1);
            if(next & one || next & two) return -1;
            if(before & one || before & two) return -1;
            cnt++;
        }
    }
    return cnt;
}

int func(int before, int bit, int row)
{

    int cnt = 0;
    int next = 0;

    cnt = check(before, bit);

    if(cnt == -1) return 0;

    if (dp[bit][row] != -1)
    {
        return dp[bit][row];
    }

    if (row != N)
    {
        for (int i = 0; i < (1 << M); i++)
        {
            if(map[row] & i) continue;
            next = max(next, func(bit, i, row + 1));
        }
    }

    dp[bit][row] = cnt + next;
    return dp[bit][row];
}

int main()
{
    char str;
    int T, result = 0;
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
        memset(dp, -1, sizeof(dp));

        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++)
        {
            map[i] = 0;
            for (int j = 0; j < M; j++)
            {
                scanf(" %c", &str);
                if (str == 'x') map[i] |= (1 << j);
            }
        }

        for (int i = 0; i < (1 << M); i++)
        {
            if (map[0] & i) continue;
            result = max(result, func(0, i, 1));
        }

        printf("%d\n", result);
        result = 0;
    }
}