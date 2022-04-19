#include<stdio.h>

int com[100][100] = {0,};

int visit[100] = { 1, 0, };

int count = -1, m, n;

void func(int num) {

    count++;

    for(int i = 0; i < n; i++) {

        if(count == n) {
            return;
        }

        if(com[num][i] && !visit[i]) {
            visit[i] = 1;
            func(i);
        }
    }
}

int main() {
    int x, y;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        com[x - 1][y - 1] = 1;
        com[y - 1][x - 1] = 1;
    }
    func(0);
    printf("%d", count);
}