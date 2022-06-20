#include <stdio.h>
#include <vector>

#define max(a, b) (a > b ? a : b)

using namespace std;

int answer;
int dp[502][502] = {0,};

int solution(vector<vector<int>> triangle) {
    int N = triangle.size();
    for(int i = N - 1; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
        }
    }

    return dp[0][0];
}