#include<stdio.h>
#include<string.h>

#define ll long long

int len[15] = {0,};
int list[15] = {0,};
int ten[51] = {1,};
char pmt[15][51];
ll dp[100][1 << 15];
int N, K;

void operator(int idx) {
    for(int i = 0; pmt[idx][i] != '\0'; i++) {
        list[idx] = list[idx] * 10 + (pmt[idx][i] - '0');
        list[idx] %= K;
        len[idx]++;
    }
}

ll solve(int sum, int visit) {

    if(visit == (1 << N) - 1) return (sum % K == 0);

    if(dp[sum][visit] != -1) {
        return dp[sum][visit];
    }

    dp[sum][visit] = 0;

    for(int i = 0; i < N; i++) {

        if(!(visit & (1 << i))) {
            dp[sum][visit] += solve((sum * ten[len[i]] + list[i]) % K, visit | (1 << i));
        }
    }

    return dp[sum][visit];
}

ll gcd(ll a, ll b) {
    if(b) return gcd(b, a % b);
    return a;
}

int main() {
    ll q = 1;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%s", pmt[i]);
        q *= (i + 1);
    }
    scanf("%d", &K);
    for(int i = 0; i < N; i++) {
        operator(i);
    }
    for(int i = 1; i <= 50; i++) {
        ten[i] = (ten[i - 1] * 10) % K;
    }

    memset(dp, -1, sizeof(dp));
    ll result = solve(0, 0);

    ll MOD = gcd(result, q);
    
    printf("%lld/%lld", result / MOD, q / MOD);
}