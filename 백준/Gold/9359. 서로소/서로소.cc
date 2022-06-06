#include<stdio.h>
#include<vector>

using namespace std;

#define ll long long

ll recurse(vector<ll>& arr, int idx, ll sum, ll end) {
    if(idx == arr.size() || arr[idx] * sum > end) return 0;
    ll ret = (end / arr[idx]) / sum;
    ret += recurse(arr, idx + 1, sum, end);
    ret -= recurse(arr, idx + 1, sum * arr[idx], end);
    return ret;
}

ll answer(ll A, ll B, ll N) {
    ll ans = B - A + 1;
    vector<ll> arr;
    for(ll i = 2LL; i * i <= N; i++) {
        if(N % i == 0) {
            arr.push_back(i);

            do {
                N /= i;
            } while(N % i == 0);
        }
    }
    if(N > 1) {
        arr.push_back(N);
    }
    return ans - (recurse(arr, 0, 1, B) - recurse(arr, 0, 1, A - 1));
}

int main() {
    int T;
    ll N, A, B, ans;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        scanf("%lld %lld %lld", &A, &B, &N);
        printf("Case #%d: %lld\n", i, answer(A, B, N));
    }
}