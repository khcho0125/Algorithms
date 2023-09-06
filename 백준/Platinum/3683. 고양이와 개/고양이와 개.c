#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define V_MAX 500
#define NO_CHOICE -1

typedef enum Animal {
    Cat = 'C',
    Dog = 'D'
}A;

typedef struct Vote {
    int win, lose;
}V;

bool graph[V_MAX][V_MAX];
V result[V_MAX];

int choice[V_MAX];
int visit[V_MAX];
int v;

bool dfs(int idx, int turn) {

    if(visit[idx] == turn) return false;

    visit[idx] = turn;

    for(int i = 0; i < v; i++) {
        if(graph[idx][i] && (choice[i] == NO_CHOICE || dfs(choice[i], turn))) {
            choice[i] = idx;
            return true;
        }
    }

    return false;
}

int bipartite() {
    memset(choice, NO_CHOICE, sizeof(choice));
    memset(visit, 0, sizeof(visit));
    int crash = 0;

    for(int i = 0; i < v; i++) {
        if(result[i].win > 0) crash += dfs(i, i + 1);
    }

    return crash;
}

int main() {
    char wa, la;
    int T, c, d;
    scanf("%d", &T);
    while(T--) {
        memset(graph, false, sizeof(graph));
        scanf("%d %d %d", &c, &d, &v);

        for(int i = 0; i < v; i++) {
            scanf(" %c%d %c%d", &wa, &result[i].win, &la, &result[i].lose);
            if(wa == Dog) result[i].win *= -1;
            else result[i].lose *= -1;

            for(int j = 0; j < i; j++) {
                if(result[i].win == result[j].lose || result[i].lose == result[j].win) {
                    graph[i][j] = graph[j][i] = true;
                }
            }
        }

        printf("%d\n", v - bipartite());
    }
}