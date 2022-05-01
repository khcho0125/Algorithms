#include <string>
#include <vector>

using namespace std;

bool visit[200] = {0,};
bool edge[200][200] = {0,};
int N;

void DFS(int idx) {
    visit[idx] = true;
    
    for(int i = 0; i < N; i++) {
        if(edge[idx][i] && !visit[i]) DFS(i);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    N = n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            edge[i][j] = computers[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        if(!visit[i]) {
            DFS(i);
            answer++;
        }
    }
    return answer;
}