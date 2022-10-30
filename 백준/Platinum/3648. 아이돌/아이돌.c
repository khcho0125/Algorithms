#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define min(a, b) (a < b ? a : b)

typedef struct V {
    int v;
    struct V* link;
}V;

typedef struct Idol {
    V* link;
    V* back;
}Idol;

int sn[2001], visit[2001], stack[2001], scc[2001], num, cnt, temp = 0;
Idol vote[2001];

void SCC(int idx) {
    stack[temp++] = idx;
    sn[idx] = visit[idx] = ++num;
    while(vote[idx].link != NULL) {
        if(!visit[vote[idx].link->v]) {
            SCC(vote[idx].link->v);
            sn[idx] = min(sn[idx], sn[vote[idx].link->v]);
        }
        else if(!scc[vote[idx].link->v]) {
            sn[idx] = min(sn[idx], visit[vote[idx].link->v]);
        }
        vote[idx].link = vote[idx].link->link;
    }

    if(visit[idx] == sn[idx]) {
        ++cnt;
        while(stack[--temp] != idx) {
            scc[stack[temp]] = cnt;
        }
        scc[idx] = cnt;
    }
}

bool solve(int N) {
    memset(sn, 0, sizeof(sn));
    memset(visit, 0, sizeof(visit));
    memset(scc, 0, sizeof(scc));
    cnt = num = 0;

    N *= 2;
    for(int i = 0; i < N; i++) {
        if(!visit[i]) {
            SCC(i);
        }
    }                                                                          

    for(int i = 0; i < N; i += 2) {
        if(scc[i] == scc[i + 1]) {
            return false;
        }
    }
    
    return scc[1] < scc[0];
}

int main() {
    int N, M, A, B, nA, nB;
    while(~scanf("%d %d", &N, &M)) {
        V* sang = (V*)malloc(sizeof(V));
        sang->link = NULL;
        sang->v = 1;
        vote[0].back = vote[0].link = sang;

        for(int i = 0; i < M; i++) {
            scanf("%d %d", &A, &B);

            if(A < 0) {
                A = (A + 1) * -2;
                nA = A + 1;
            }
            else {
                A = A * 2 - 1;
                nA = A - 1;
            }
            if(B < 0) {
                B = (B + 1) * -2;
                nB = B + 1;
            }
            else {
                B = B * 2 - 1;
                nB = B - 1;
            }

            V* one = (V*)malloc(sizeof(V));
            one->link = NULL;
            one->v = A;
            if(vote[nB].link == NULL) {
                vote[nB].link = one;
            }
            else {
                vote[nB].back->link = one;
            }
            vote[nB].back = one;

            V* two = (V*)malloc(sizeof(V));
            two->link = NULL;
            two->v = B;
            if(vote[nA].link == NULL) {
                vote[nA].link = two;
            }
            else {
                vote[nA].back->link = two;
            }
            vote[nA].back = two;
        }

        printf(solve(N) ? "yes\n" : "no\n");
    }
}