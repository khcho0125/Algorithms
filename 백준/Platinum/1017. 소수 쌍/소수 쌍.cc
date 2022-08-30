#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>

using namespace std;

vector<int> same, other;
vector<int> result;

vector<int> map[25];
int sit[25];
bool decimal[2000];
int N, bit, cnt;

bool dfs(int x) {
    for(int i : map[x]) {
        if(!(bit & (1 << i))) {
            bit |= (1 << i);    
            if(sit[i] == -1 || dfs(sit[i])) {
                sit[i] = x;
                return true;
            }
        }
    }

    return false;
}

void match(int idx) {
    memset(sit, -1, sizeof(sit));
    sit[idx] = N - 1;
    for(cnt = 0, bit = 0; cnt < N - 1 && dfs(cnt); cnt++, bit = 0);
    if(cnt == N - 1)
        result.push_back(other[idx]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int d = 2; d <= 43; d++)
        if(!decimal[d]) for(int temp = d + d; temp < 2000; decimal[temp] = true, temp += d);

    int input, first;
    cin >> N >> first;
    for(int i = 1; i < N; i++) {
        cin >> input;
        ((first & 1) == (input & 1)) ? same.push_back(input) : other.push_back(input);
    }

    N /= 2;
    if(other.size() != N) {
        cout << -1;
        return 0;
    }

    for(int i = 0; i < N - 1; i++)
        for(int j = 0; j < N; j++)
            if(!decimal[same[i] + other[j]]) map[i].push_back(j);

    for(int i = 0; i < N; i++)
        if(!decimal[first + other[i]]) match(i);

    if(!result.size()) {
        cout << -1;
        return 0;
    }

    sort(begin(result), end(result));

    for(int i : result)
        cout << i << ' ';
}