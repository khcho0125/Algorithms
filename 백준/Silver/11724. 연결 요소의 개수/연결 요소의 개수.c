#include <stdio.h>

int arr[1001][1001] = {0,};
int visit[1000] = {0,};
int n;

void func(int num) {

    visit[num - 1] = 1;

    for(int i = 1; i <= n; i++) {
        if(arr[num][i] && !visit[i - 1]) {
            func(i);
        }
    }
}

int main()
{
    int m, a, b, cnt = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    for(int i = 0; i < n; i++) {
        if(!visit[i]) {
            func(i + 1);
            cnt++;
        }
    }
    printf("%d", cnt);
}