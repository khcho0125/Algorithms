#include<stdio.h>
#include<stdlib.h>

#define K_MAX 10001
#define min(a, b) ((a) < (b) ? a : b)

typedef enum Color {
    R = 'R',
    B = 'B'
}C;

typedef struct Clause {
    int x;
    struct Clause *link;
}CNF;

typedef struct Lamp {
    CNF *link;
    CNF *back;
}L;

L lamp[K_MAX];
int dfsn[K_MAX], pn[K_MAX];
int number = 1;

int sccSet[K_MAX];
int sccp = 1;

int stack[K_MAX];
int temp = 0;

void makeEdge(int s, int t) {
    CNF* clause = (CNF*)malloc(sizeof(CNF));
    clause->link = NULL;
    clause->x = t;

    if(lamp[s].link == NULL) lamp[s].link = clause;
    else lamp[s].back->link = clause;
    lamp[s].back = clause;
}

void parse(int* x, int* nx, C color) {
    switch(color) {
        case R:
            *x = *x * 2 - 1;
            *nx = *x - 1;
            return;
        case B:
            *x = (*x - 1) * 2;
            *nx = *x + 1;
            return;
    }
}

void SCC(int idx) {
    pn[idx] = dfsn[idx] = number++;
    stack[temp++] = idx;
    for(CNF* prev = lamp[idx].link; prev != NULL; prev = prev->link) {
        if(!dfsn[prev->x]) {
            SCC(prev->x);
            pn[idx] = min(pn[idx], pn[prev->x]);
        }
        else if(!sccSet[prev->x]) {
            pn[idx] = min(pn[idx], pn[prev->x]);
        }
    }

    if(dfsn[idx] == pn[idx]) {
        while(stack[--temp] != idx) {
            sccSet[stack[temp]] = sccp;
        }
        sccSet[idx] = sccp++;
    }
}

int main() {
    char a_color, b_color, c_color;
    int k, n, a, b, c, na, nb, nc;
    scanf("%d %d", &k, &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %c %d %c %d %c", &a, &a_color, &b, &b_color, &c, &c_color);

        parse(&a, &na, a_color);
        parse(&b, &nb, b_color);
        parse(&c, &nc, c_color);

        makeEdge(na, b);
        makeEdge(na, c);

        makeEdge(nb, a);
        makeEdge(nb, c);

        makeEdge(nc, b);
        makeEdge(nc, a);
    }

    k *= 2;
    for(int i = 0; i < k; i++) {
        if(!dfsn[i]) SCC(i);
    }

    for(int i = 0; i < k; i += 2) {
        if(sccSet[i] == sccSet[i + 1]) {
            printf("-1");
            return 0;
        }
    }

    for(int i = 0; i < k; i += 2) {
        printf("%c", sccSet[i + 1] < sccSet[i] ? 'R' : 'B');
    }
}