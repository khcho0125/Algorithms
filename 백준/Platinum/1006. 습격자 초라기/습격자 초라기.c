#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define BLOCK(a, b, w) (a + b <= w ? 1 : 2)
#define INF 987654321

int map[2][10001];
int dp[3][10001] = {0,};
int block[3];
int N, W;

int compare(int get, int last)
{
    int sub1, sub2;

    for (int i = 2; i <= N; i++)
    {
        sub1 = i - 1;
        sub2 = i - 2;

        block[0] = BLOCK(map[0][i], map[0][sub1], W);
        block[1] = BLOCK(map[1][i], map[1][sub1], W);
        block[2] = BLOCK(map[0][i], map[1][i], W);

        dp[0][i] = min(
            dp[1][sub1] + block[0],
            dp[2][sub1] + 1);

        dp[1][i] = min(
            dp[0][sub1] + block[1],
            dp[2][sub1] + 1);

        dp[2][i] = min(
            dp[0][sub1] + block[1] + 1,
            min(
                dp[1][sub1] + block[0] + 1,
                min(
                    dp[2][sub1] + block[2],
                    dp[2][sub2] + block[0] + block[1])));
    }

    return dp[get][N - last];
}

int main()
{
    int T, result, MAP;
    scanf("%d", &T);
    for (int C = 0; C < T; C++)
    {
        scanf("%d %d", &N, &W);
        for (int i = 0; i < 2; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                scanf("%d", &map[i][j]);
            }
        }

        // 선형
        dp[0][1] = 1;
        dp[1][1] = 1;
        dp[2][1] = BLOCK(map[0][1], map[1][1], W);
        result = compare(2, 0);

        dp[2][1] = 2;

        // 상단
        if(N != 1 && map[0][1] + map[0][N] <= W) {
            MAP = map[0][1];
            map[0][1] = INF;
            result = min(result, compare(1, 0));
            map[0][1] = MAP;
        }

        // 하단
        if(N != 1 && map[1][1] + map[1][N] <= W) {
            MAP = map[1][1];
            map[1][1] = INF;
            result = min(result, compare(0, 0));
            map[1][1] = MAP;
        }

        // 상단 + 하단
        if(N != 1 && map[1][1] + map[1][N] <= W && map[0][1] + map[0][N] <= W) {
            dp[0][1] = 0;
            dp[1][1] = 0;
            dp[2][1] = 0;
            result = min(result, compare(2, 1) + BLOCK(map[0][1], map[0][N], W) + BLOCK(map[1][1], map[1][N], W));
        }
        
        printf("%d\n", result);
    }
}