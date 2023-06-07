#include<stdio.h>
#include<string.h>

#define INF 987654321
#define min(a, b) ((a) < (b) ? a : b)

char mbti[5];
int array[100000];

int dp[16][16];

int mbtitoi() {
    int value = 0;
    value += (mbti[0] == 'E' ? 0 : 1);
    value += (mbti[1] == 'S' ? 0 : 2);
    value += (mbti[2] == 'T' ? 0 : 4);
    value += (mbti[3] == 'J' ? 0 : 8);
    return value;
}

int find(int a, int b) {
    if (dp[a][b] != -1) return dp[a][b];

    dp[a][b] = 0;

    int value = a ^ b;
    for(int i = 1; i <= 8; i = i << 1) {
        if (value & i) dp[a][b]++;
    }

    return dp[b][a] = dp[a][b];
}

int main() {
    memset(dp, -1, sizeof(dp));

    int T, N;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        for(int i = 0; i < N; i++) {
            scanf("%s", mbti);
            array[i] = mbtitoi();
        }

        int ans = INF;

        if(N > 32) ans = 0;
        else {
            for(int i = 0; i < N - 2; i++) {
                for(int j = i + 1; j < N - 1; j++) {
                    for(int k = j + 1; k < N; k++) {
                        int ab = find(array[i], array[j]);
                        int ac = find(array[i], array[k]);
                        int bc = find(array[j], array[k]);

                        ans = min(ans, ab + ac + bc);
                    }
                }
            }
        }

        printf("%d\n", ans);
    } 
}