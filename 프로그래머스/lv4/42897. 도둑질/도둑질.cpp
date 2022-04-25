#include <string>
#include <vector>

#define INF -987654321
#define max(a, b) ((a > b) ? a : b)

int dp[1000000];

using namespace std;

int solution(vector<int> money) {
    int T1, T2, n = money.size();
    dp[0] = INF;
    dp[1] = money[1];
    dp[2] = money[2];
    for(int i = 3; i < n; i++) {
        dp[i] = money[i] + max(dp[i - 2], dp[i - 3]);
    }
    T1 = max(dp[n - 1], dp[n - 2]);
    dp[0] = money[0];
    dp[1] = money[1];
    dp[2] = money[2] + money[0];
    for(int i = 3; i < n; i++) {
        dp[i] = money[i] + max(dp[i - 2], dp[i - 3]);
    }
    T2 = max(dp[n - 2], dp[n - 3]);
    return max(T1, T2);
}