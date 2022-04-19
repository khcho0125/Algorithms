#include<iostream>
using namespace std;

char map[1000][1000];
bool visited[1000][1000] = {0,};
int N, M;

void DFS(int x, int y) {
    
    if(x >= 0 && map[x - 1][y] == 'D' && !visited[x - 1][y]) {
        visited[x - 1][y] = true;
        DFS(x - 1, y);
    }

    if(y >= 0 && map[x][y - 1] == 'R' && !visited[x][y - 1]) {
        visited[x][y - 1] = true;
        DFS(x, y - 1);
    }

    if(x < N && map[x + 1][y] == 'U' && !visited[x + 1][y]) {
        visited[x + 1][y] = true;
        DFS(x + 1, y);
    }

    if(y < M && map[x][y + 1] == 'L' && !visited[x][y + 1]) {
        visited[x][y + 1] = true;
        DFS(x, y + 1);
    }

    switch(map[x][y]) {
        case 'D':
            x++;
            break;
        case 'U':
            x--;
            break;
        case 'R':
            y++;
            break;
        case 'L':
            y--;
    }

    if(x >= 0 && x < N && y >= 0 && y < M && !visited[x][y]) {
        visited[x][y] = true;
        DFS(x, y);
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int cnt = 0;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(!visited[i][j]) {
                visited[i][j] = true;
                DFS(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
}