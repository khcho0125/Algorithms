#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b) ((a < b) ? a : b)
#define INF 987654321

typedef struct Queue
{
    int x;
    int y;
} Q;

Q chicken[250];
int pre = 0;
Q house[100] = {0,};
int visit[13] = {0,};
int result = INF, home = 0;
int N, M;

int Route(Q a, Q b) {
    int A = a.x - b.x;
    int B = a.y - b.y;

    if(A < 0) {
        A *= -1;
    }
    if(B < 0) {
        B *= -1;
    }

    return A + B;
}

void DFS(int start, int end, int cnt) {
    if(cnt == 0) {
        int temp = 0;
        for(int i = 0; i < home; i++) {
            int sum = INF;
            for(int j = 0; j < pre; j++) {
                if(visit[j]) {
                    sum = min(sum, Route(chicken[j], house[i]));
                }
            }
            temp += sum;
        }
        result = min(temp, result);
        return;
    }

    if(start == end) {
        return;
    }

    visit[start] = 1;
    DFS(start + 1, end, cnt - 1);
    visit[start] = 0;
    DFS(start + 1, end, cnt);
}

int main()
{
    int input;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &input);
            if (input == 2)
            {
                chicken[pre].x = i;
                chicken[pre++].y = j;
            }
            else if(input == 1) {
                house[home].x = i;
                house[home++].y = j;
            }
        }
    }
    DFS(0, pre, M);
    printf("%d", result);
}