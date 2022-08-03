#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define not(a) (a % 2 == 0 ? a + 1 : a - 1)
#define min(a, b) (a < b ? a : b);

typedef struct Clause {
    int x;
    struct Clause* link;
}CNF;

typedef struct Variable {
    CNF* link;
    CNF* back;
}Var;

int dfsn[20000] = {0,}, sn[20000] = {0,}, stack[20000];
bool finish[20000];
Var value[20000];
int num = 1, temp = 0;

void SCC(int idx) {
    dfsn[idx] = num++;
    sn[idx] = dfsn[idx];
    stack[temp++] = idx;
    while(value[idx].link != NULL) {
        if(!dfsn[value[idx].link->x]) {
            SCC(value[idx].link->x);
            sn[idx] = min(sn[value[idx].link->x], sn[idx]);
        }
        else if(!finish[value[idx].link->x]) {
            sn[idx] = min(dfsn[value[idx].link->x], sn[idx]);
        }
        value[idx].link = value[idx].link->link;
    }

    if(dfsn[idx] == sn[idx]) {
        while(stack[--temp] != idx) {
            sn[stack[temp]] = dfsn[idx];
        }
    }

    finish[idx] = true;
}

int main() {
    int N, M, A, B, nA, nB;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &A, &B);
        A = A < 0 ? (A + 1) * -2 : A * 2 - 1;
        B = B < 0 ? (B + 1) * -2 : B * 2 - 1;
        
        nA = not(A);
        nB = not(B);

        CNF* one = (CNF*)malloc(sizeof(CNF));
        one->link = NULL;
        one->x = B;
        if(value[nA].link == NULL) {
            value[nA].link = one;
        }
        else {
            value[nA].back->link = one;
        }
        value[nA].back = one;

        CNF* two = (CNF*)malloc(sizeof(CNF));
        two->link = NULL;
        two->x = A;
        if(value[nB].link == NULL) {
            value[nB].link = two;
        }
        else {
            value[nB].back->link = two;
        }
        value[nB].back = two;
    }

    for(int i = 0; i < N * 2; i++) {
        if(!dfsn[i]) {
            SCC(i);
        }
    }

    for(int i = 0; i < N; i++) {
        if(sn[i * 2] == sn[i * 2 + 1]) {
            printf("0");
            return 0;
        }
    }

    printf("1");
}