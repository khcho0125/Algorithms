#include<stdio.h>
#include<stdlib.h>

#define INF 987654321

typedef struct Node {
    int x, y;
    int w;
}node;

int dist[125][125];
int map[125][125];
node Priority_Queue[20000];
int pre = 0;
int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, -1, 1};

void Q_I(int x, int y, int w) {
    int child = ++pre;
    while(child != 1 && Priority_Queue[child / 2].w > w) {
        Priority_Queue[child].w = Priority_Queue[child / 2].w;
        Priority_Queue[child].x = Priority_Queue[child / 2].x;
        Priority_Queue[child].y = Priority_Queue[child / 2].y;
        child /= 2;
    }
    Priority_Queue[child].x = x;
    Priority_Queue[child].y = y;
    Priority_Queue[child].w = w;
}

node* Q_O() {
    node* first = (node*)malloc(sizeof(node));
    first->x = Priority_Queue[1].x;
    first->y = Priority_Queue[1].y;
    first->w = Priority_Queue[1].w;
    node temp = Priority_Queue[pre--];
    int parent = 1, child = 2;
    while(child <= pre) {
        if(child + 1 < pre && Priority_Queue[child].w > Priority_Queue[child + 1].w) {
            child++;
        }

        if(temp.w < Priority_Queue[child].w) {
            break;
        }

        Priority_Queue[parent].y = Priority_Queue[child].y;
        Priority_Queue[parent].x = Priority_Queue[child].x;
        Priority_Queue[parent].w = Priority_Queue[child].w;
        parent = child;
        child *= 2;
    }
    Priority_Queue[parent] = temp;
    return first;
}

void dijkstra(int N) {
    dist[0][0] = map[0][0];
    Q_I(0, 0, map[0][0]);
    while(pre != 0) {
        node* tmp = (node*)malloc(sizeof(node));
        tmp = Q_O();
        for(int i = 0; i < 4; i++) {
            if(tmp->x + x[i] != N && tmp->x + x[i] >= 0 && tmp->y + y[i] != N && tmp->y + y[i] >= 0 && dist[tmp->x + x[i]][tmp->y + y[i]] > tmp->w + map[tmp->x + x[i]][tmp->y + y[i]]) {
                dist[tmp->x + x[i]][tmp->y + y[i]] = tmp->w + map[tmp->x + x[i]][tmp->y + y[i]];
                Q_I(tmp->x + x[i], tmp->y + y[i], dist[tmp->x + x[i]][tmp->y + y[i]]);
            }
        }
    }
}

int main() {
    int TC, turn = 1;
    scanf("%d", &TC);
    while(TC != 0) {
        for(int i = 0; i < TC; i++) {
            for(int j = 0; j < TC; j++) {
                scanf("%d", &map[i][j]);
                dist[i][j] = INF;
            }
        }
        dijkstra(TC);
        printf("Problem %d: %d\n", turn++, dist[TC - 1][TC - 1]);
        scanf("%d", &TC);
    }
}