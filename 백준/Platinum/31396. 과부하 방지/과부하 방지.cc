#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long

using namespace std;

vector<int> electronics;
vector<int> tap;

int solution(int K);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> K >> M;

    tap = vector<int>(N);
    electronics = vector<int>(M);
    
    for(int i = 0; i < N; i++) {
        cin >> tap[i];
    }
    for(int i = 0; i < M; i++) {
        cin >> electronics[i];
    }

    cout << solution(K);
}

bool connectable(int cnt, ll k) {
    ll usedTap = 0;
    for(int depth = 0; cnt && electronics[cnt - 1] >= depth; depth++) {
        while(cnt && k && electronics[cnt - 1] == depth) {
            cnt--;
            k--;
        }

        ll tapLast = min(usedTap + k, (ll)tap.size());
        for(; usedTap < tapLast; usedTap++) {
            k += tap[usedTap] - 1;
        }
    }

    return k >= cnt;
}

int solution(int K) {
    sort(tap.begin(), tap.end(), greater<>());
    sort(electronics.begin(), electronics.end(), greater<>());

    int s = 0, e = electronics.size() + 1;
    while(s + 1 < e) {
        int mid = (s + e) / 2;

        if(connectable(mid, K)) {
            s = mid;
        }
        else {
            e = mid;
        }
    }

    return s;
}