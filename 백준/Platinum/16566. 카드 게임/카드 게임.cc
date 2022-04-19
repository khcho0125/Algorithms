#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> CardPack;
int UnionFind[4000001] = {0,};
int M;

int find(int x) {
    if(UnionFind[x] == 0) {
        return x;
    }
    return UnionFind[x] = find(UnionFind[x]);
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);

    UnionFind[x] = y;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N, M, K, card, lower, upper;

    cin >> N >> M >> K;
    for(int i = 0; i < M; i++) {
        cin >> card;
        CardPack.push_back(card);
    }
    sort(CardPack.begin(), CardPack.end());
    CardPack.push_back(4000001);
    for(int i = 0; i < K; i++) {
        cin >> card;
        lower = find(upper_bound(CardPack.begin(), CardPack.end(), card) - CardPack.begin());
        cout << CardPack[lower] << "\n";
        Union(lower, lower + 1);
    }
}