#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct Edge {
    int v;
    struct Edge* link;
}Edge;

typedef struct Graph {
    Edge* link;
    Edge* back;
    Edge* reverse;
    Edge* reverse_back;
}G;

vector<vector<int>> ans;
int result = 0;
G graph[10001];
int visit[10001] = {0,};
int stack[10000];
int pre = 0;

void DFS(int idx) {
    Edge* cnet = (Edge*)malloc(sizeof(Edge));
    cnet = graph[idx].link;
    while(cnet != NULL) {
        if(!visit[cnet->v]) {
            visit[cnet->v] = 1;
            DFS(cnet->v);
            stack[pre++] = cnet->v;
        }
        cnet = cnet->link;
    }
}

void RDFS(int idx) {
    ans[result - 1].push_back(idx);
    Edge* cnet = (Edge*)malloc(sizeof(Edge));
    cnet = graph[idx].reverse;
    while(cnet != NULL) {
        if(!visit[cnet->v]) {
            visit[cnet->v] = 1;
            RDFS(cnet->v);
        }
        cnet = cnet->link;
    }
}

int main() {
    int V, E, v1, v2;
    scanf("%d %d", &V, &E);
    for(int i = 0; i < E; i++) {
        scanf("%d %d", &v1, &v2);
        Edge* one = (Edge*)malloc(sizeof(Edge));
        one->link = NULL;
        one->v = v2;
        if(graph[v1].link == NULL) {
            graph[v1].link = one;
        }
        else {
            graph[v1].back->link = one;
        }
        graph[v1].back = one;

        Edge* two = (Edge*)malloc(sizeof(Edge));
        two->link = NULL;
        two->v = v1;
        if(graph[v2].reverse == NULL) {
            graph[v2].reverse = two;
        }
        else {
            graph[v2].reverse_back->link = two;
        }
        graph[v2].reverse_back = two;
    }

    for(int i = 1; i <= V; i++) {
        if(!visit[i]) {
            visit[i] = 1;
            DFS(i);
            stack[pre++] = i;
        }
    }

    memset(visit, 0, sizeof(visit));
    while(pre--) {
        if(!visit[stack[pre]]) {
            visit[stack[pre]] = 1;
            ans.push_back(vector<int>());
            result++;
            RDFS(stack[pre]);
        }
    }
    

    for(int i = 0; i < result; i++) {
        sort(begin(ans[i]), end(ans[i]));
    }
    sort(begin(ans), end(ans));
    

    printf("%d\n", result);
    for(int i = 0; i < result; i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            printf("%d ", ans[i][j]);
        }
        printf("-1\n");
    }
}