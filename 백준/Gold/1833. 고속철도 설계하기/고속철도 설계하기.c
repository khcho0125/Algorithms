#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define min(a, b) (a < b ? a : b)

typedef struct Edge {
    int s, e, w;
}Edge;

Edge road[40000];
int temp = 0;

int unionFind[201];

int buildRoad[200];
int road_temp = 0;

int compare(const void* a, const void* b) {
    Edge r1 = *(Edge*)a;
    Edge r2 = *(Edge*)b;

    return r1.w > r2.w;
}

int find(int x) {
    if(unionFind[x] < 0) {
        return x;
    }
    return unionFind[x] = find(unionFind[x]);
}

bool Union(int s, int e) {
    s = find(s);
    e = find(e);

    if(s == e) {
        return false;
    }

    if(unionFind[s] <= unionFind[e]) {
        unionFind[s] += unionFind[e];
        unionFind[e] = s;
    }

    else {
        unionFind[e] += unionFind[s];
        unionFind[s] = e;
    }

    return true;
}

int main() {
    memset(unionFind, -1, sizeof(unionFind));

    int N, W;
    scanf("%d", &N);

    int C = 0, M = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            scanf("%d", &W);
            
            if(i != j && W > 0) {
                road[temp++] = (Edge){
                    .s = i,
                    .e = j,
                    .w = W
                };
            }
            else if(i < j) {
                Union(i, j);
                C -= W;
            }
        }
    }

    qsort(road, temp, sizeof(Edge), compare);
    
    for(int i = 0; i < temp; i++) {
        if (Union(road[i].s, road[i].e)) {    
            C += road[i].w;
            M++;
            buildRoad[road_temp++] = i;
        }
    }

    printf("%d %d\n", C, M);
    for(int i = 0; i < road_temp; i++) {
        printf("%d %d\n", road[buildRoad[i]].s, road[buildRoad[i]].e);
    }
}