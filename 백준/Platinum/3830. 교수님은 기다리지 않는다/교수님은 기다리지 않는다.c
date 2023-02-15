#include<stdio.h>
#include<string.h>

typedef struct Sample {
    int u, w;
}Sample;

Sample set[100001];

Sample find(int x) {
    if(!set[x].u) {
        return (Sample){.u = x, .w = 0};
    }
    
    Sample sp = find(set[x].u);
    return set[x] = (Sample){.u = sp.u, .w = sp.w + set[x].w};
}

void Union(int a, int b, int w) {

    Sample Ua = find(a);
    Sample Ub = find(b);

    if(Ua.u == Ub.u) return;

    set[Ub.u] = (Sample){.u = Ua.u, .w = Ua.w + w - Ub.w};
}

void query(int a, int b) {
    Sample Ua = find(a);
    Sample Ub = find(b);

    if(Ua.u != Ub.u) {
        printf("UNKNOWN\n");
        return;
    }

    printf("%d\n", Ub.w - Ua.w);
}

void execute(int N, int M) {
    char cmd;
    int a, b, w;
    for(int i = 0; i < M; i++) {
        scanf(" %c %d %d", &cmd, &a, &b);
        if(cmd == '!') {
            scanf("%d", &w);
            Union(a, b, w);
        }
        else {
            query(a, b);
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    while(N || M) {
        execute(N, M);
        memset(set, 0, sizeof(set));
        scanf("%d %d", &N, &M);
    }
}