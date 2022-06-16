#include<stdio.h>
#include<string.h>

#define abs(a) ((a) > 0 ? a : (a) * (-1))
#define min(a, b) ((a) < (b) ? a : b)
#define max(a, b) ((a) > (b) ? a : b)
#define INF 987654321

typedef struct Incident {
    int x, y;
}Point;

Point input[1001];
int dp[1001][1001];
int stick[1001][1001] = {0,};
int W, N;

int length(int p1, int p2) {

    Point A = input[p1];
    Point B = input[p2];

    if(!p2) {
        B.x = N;
        B.y = N;
    }
    
    return abs(A.x - B.x) + abs(A.y - B.y);
}

int track(int one, int two, int next) {

    if(one == W || two == W) return 0;
    if(dp[one][two] != -1) return dp[one][two];

    stick[one][next] = length(one, next);
    stick[next][two] = length(next, two);
    return dp[one][two] = min(track(next, two, next + 1) + stick[one][next], track(one, next, next + 1) + stick[next][two]);
}

void backTrack(int one, int two, int next) {
    if(next > W) return;

    if(dp[next][two] == -1) dp[next][two] = 0;
    if(dp[one][next] == -1) dp[one][next] = 0;

    if(dp[one][two] == dp[next][two] + stick[one][next]) {
        printf("1\n");
        backTrack(next, two, next + 1);
    }
    else {
        printf("2\n");
        backTrack(one, next, next + 1);
    }
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d %d", &N, &W);
    input[0].x = 1;
    input[0].y = 1;
    for(int i = 1; i <= W; i++) {
        scanf("%d %d", &input[i].x, &input[i].y);
    }

    printf("%d\n", track(0, 0, 1));
    backTrack(0, 0, 1);
}