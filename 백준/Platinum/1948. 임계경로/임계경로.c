#include<stdio.h>
#include<stdlib.h>

typedef struct Edge {
    int v;
    int t;
    struct Edge* link;
}edge;

typedef struct City {
    edge* link;
    edge* back;

    edge* reverse;
    edge* reverse_back;
    int cnt;
    int max;
}C;

C city[10001];
int queue[100001];
int visit[100001] = {0,};
int back = 0, front = 0;
int result = 0;

void solve() {
    int idx;
    edge* temp = (edge*)malloc(sizeof(edge));
    while(front != back) {
        idx = queue[front++];
        temp = city[idx].link;
        while(temp != NULL) {
            city[temp->v].cnt--;
            if(city[temp->v].max < city[idx].max + temp->t) {
                city[temp->v].max = city[idx].max + temp->t;
            }
            if(!city[temp->v].cnt) {
                queue[back++] = temp->v;
            }
            temp = temp->link;
        }
    }
}

void count() {
    int idx;
    edge* temp = (edge*)malloc(sizeof(edge));
    while(front != back) {
        idx = queue[front++];
        temp = city[idx].reverse;
        while(temp != NULL) {
            if(city[temp->v].max == city[idx].max - temp->t) {
                result++;
                if(!visit[temp->v]) {
                    visit[temp->v] = 1;
                    queue[back++] = temp->v;
                }
            }
            temp = temp->link;
        }
    }
}

int main() {
    int n, m, v1, v2, w, s, e;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        edge* one = (edge*)malloc(sizeof(edge));
        scanf("%d %d %d", &v1, &v2, &w);
        one->v = v2;
        one->t = w;
        one->link = NULL;
        if(city[v1].link == NULL) {
            city[v1].link = one;
        }
        else {
            city[v1].back->link = one;
        }
        city[v1].back = one;
        city[v2].cnt++;

        edge* two = (edge*)malloc(sizeof(edge));
        two->link = NULL;
        two->v = v1;
        two->t = w;
        if(city[v2].reverse == NULL) {
            city[v2].reverse = two;
        }
        else {
            city[v2].reverse_back->link = two;
        }
        city[v2].reverse_back = two;
    }
    scanf("%d %d", &s, &e);

    queue[back++] = s;
    solve();

    front = 0; back = 0;
    queue[back++] = e;
    count();

    printf("%d\n%d", city[e].max, result);
}