#include<stdio.h>
#include<string.h>

#define max(a, b) (a > b ? a : b)

int dp[1500][1500];
char medicine[1500];

typedef enum MEAL {
    BREAKFAST = 0,
    LUNCH = 1,
    DINNER = 2
}MEAL;

const char meal[3] = {'B', 'L', 'D'};

int eat(int front, int back, int status) {

    if(front > back) return 0;

    if(dp[front][back] != -1) {
        return dp[front][back];
    }

    dp[front][back] = 0;

    if (medicine[front] == meal[status]) {
        dp[front][back] = eat(front + 1, back, (status + 1) % 3) + 1;
    }

    if (medicine[back] == meal[status]) {
        int value = eat(front, back - 1, (status + 1) % 3) + 1;
        dp[front][back] = max(dp[front][back], value);
    }

    return dp[front][back];
}

int main() {
    memset(dp, -1, sizeof(dp));

    int N;
    scanf("%d", &N);
    scanf("%s", medicine);

    printf("%d", eat(0, N * 3 - 1, 0));
}