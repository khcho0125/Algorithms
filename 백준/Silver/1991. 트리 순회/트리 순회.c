#include<stdio.h>
#include<stdlib.h>

char TREE[26][2] = {0,};

void first(int idx) {
    printf("%c", idx + 'A');
    if(TREE[idx][0] != '.') {
        first(TREE[idx][0] - 'A');
    }
    if(TREE[idx][1] != '.') {
        first(TREE[idx][1] - 'A');
    }
}

void middle(int idx) {
    if(TREE[idx][0] != '.') {
        middle(TREE[idx][0] - 'A');
    }
    printf("%c", idx + 'A');
    if(TREE[idx][1] != '.') {
        middle(TREE[idx][1] - 'A');
    }
}

void last(int idx) {
    if(TREE[idx][0] != '.') {
        last(TREE[idx][0] - 'A');
    }
    if(TREE[idx][1] != '.') {
        last(TREE[idx][1] - 'A');
    }
    printf("%c", idx + 'A');
}

int main() {
    int N;
    char one;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf(" %c", &one);
        scanf(" %c %c", &TREE[one - 'A'][0], &TREE[one - 'A'][1]);
    }
    first(0);
    printf("\n");
    middle(0);
    printf("\n");
    last(0);
}