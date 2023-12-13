#include<iostream>
#include<unordered_map>

#define N_MAX 200000

using namespace std;

int network[N_MAX];

int find(int x) {
    if(network[x] < 0) return x;
    return network[x] = find(network[x]);
}

int Union(int a, int b) {
    int aroot = find(a);
    int broot = find(b);

    if(aroot == broot) return -network[aroot];

    if(network[aroot] < network[broot]) {
        network[aroot] += network[broot];
        network[broot] = aroot;
        return -network[aroot];
    }

    network[broot] += network[aroot];
    network[aroot] = broot;
    return -network[broot];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, F;
    string a, b;
    cin >> T;
    while(T--) {
        unordered_map<string, int> user{};
        int userIndex = 0;

        fill_n(network, N_MAX, -1);

        cin >> F;
        for(int i = 0; i < F; i++) {
            cin >> a >> b;

            if(user.find(a) == user.end()) user.insert({a, ++userIndex});
            if(user.find(b) == user.end()) user.insert({b, ++userIndex});

            cout << Union(user[a], user[b]) << '\n';
        }
    }
}