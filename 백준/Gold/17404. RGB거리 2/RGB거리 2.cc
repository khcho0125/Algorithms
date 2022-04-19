#include <iostream>

#define min(a, b) ((a < b) ? a : b)
#define INF 1000001

using namespace std;

int dp[3][1000] = {0,};
int input[3][1000] = {0,};

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, Result = INF;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> input[0][i] >> input[1][i] >> input[2][i];
    }
    for(int color = 0; color < 3; color++) {
        dp[0][0] = INF;
        dp[1][0] = INF;
        dp[2][0] = INF;
        dp[color][0] = input[color][0];
        for(int i = 1; i < N; i++) {
            dp[0][i] = input[0][i] + min(dp[1][i - 1], dp[2][i - 1]);
            dp[1][i] = input[1][i] + min(dp[0][i - 1], dp[2][i - 1]);
            dp[2][i] = input[2][i] + min(dp[1][i - 1], dp[0][i - 1]);
        }
        for(int i = 0; i < 3; i++) {
            if(i != color) {
                Result = min(Result, dp[i][N - 1]);
            }
        }
    }
    cout << Result;
}