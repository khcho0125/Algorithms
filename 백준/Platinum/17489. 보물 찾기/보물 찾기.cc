#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, M, L;
string S;
vector<vector<char>> map;
vector<vector<bool>> visited;

int result = -1;
int rx = -1, ry = -1;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void DFS(int x, int y, int idx, int K);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> L;
    cin >> S;

    map = vector<vector<char>>(N + 2, vector<char>(M + 2));
    visited = vector<vector<bool>>(N + 2, vector<bool>(M + 2));

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            cin >> map[i][j];

    if(map[1][1] == S[0])
        DFS(1, 1, 0, 0);

    cout << result << '\n';

    if(result != -1)
        cout << rx << ' ' << ry;
}

bool cycle = false;

void DFS(int x, int y, int idx, int K) {
    if(cycle || x <= 0 || N < x || y <= 0 || M < y)
        return;
    
    visited[x][y] = true;

    if(idx + 1 == L && result < K + 1) {
        result = K + 1;
        rx = x, ry = y;
    }

    for(int i = 0; i < 4; i++) {
        if(map[x + dx[i]][y + dy[i]] == S[(idx + 1) % L]) {

            if(visited[x + dx[i]][y + dy[i]]) {
                result = -1;
                cycle = true;
                return;
            }

            DFS(x + dx[i], y + dy[i], (idx + 1) % L, (idx + 1) / L + K);
        }
    }

    visited[x][y] = false;
}