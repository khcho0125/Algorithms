#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

#define ll long long
#define ld long double

#define INF 1e18
#define EXPONENT_MAX 62
#define A_MAX 1000000000
#define DP_SIZE 1000000
#define LIMIT (1ULL << 63) - 1

#define abs(x) ((x) < 0 ? (x) * -1 : x)
#define min(a, b) ((a) < (b) ? a : b)

const ld LOG_LIMIT = logl(LIMIT);

ll dp[DP_SIZE];
ll limit[EXPONENT_MAX + 1];

ll find_a(ll k, ll n, ll maximum) {
    ll low = 1, high = maximum;
    while(low + 1 < high) {
        ll mid = (low + high) / 2;
        if(n <= powl(mid, k)) {
            high = mid;
        }
        else {
            low = mid;
        }
    }
    return high;
}

ll find_limit(ll k, ll maximum) {
    ll low = 2, high = maximum;
    while(low + 1 < high) {
        ll mid = (low + high) / 2;
        if(logl(mid) * k < LOG_LIMIT) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return low;
}

ll operation(ll N) {
    if(N < DP_SIZE && dp[N] != -1) return dp[N];

    ll result = N - 1, move, k, current;
    ll maxB = ceill(log2(N));
    for(ll b = 2; b <= maxB; b++){
        ll a = find_a(b, N, limit[b]);

        move = operation(a);
        k = powl(a, b);
        current = abs(N - k);

        result = min(result, move + current + 1);

        move = operation(a - 1);
        k = powl(a - 1, b);
        current = abs(N - k);

        result = min(result, move + current + 1);
    }

    if(N < DP_SIZE) dp[N] = result;

    return result;
}

ll solution(ll N) {  
    for(ll b = 2; b <= EXPONENT_MAX; b++) {
        limit[b] = find_limit(b, INF);
    }

    return operation(N);
}

int main() {
    memset(dp, -1, sizeof(dp));
    dp[1] = 0;

    ll N;
    scanf("%lld", &N);
    printf("%lld", solution(N));
}