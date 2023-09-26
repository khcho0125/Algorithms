#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define BIT_MAX 29

enum COMMAND {
    ADD = 1,
    REMOVE = 2,
    XOR = 3
};

typedef struct Trie {
    int cnt;
    struct Trie *next[2];
}T;

T sequence;

void insert(T* link, int value, int depth) {
    link->cnt++;

    if(depth >= 0) {
        bool bit = value & (1 << depth);
        if(link->next[bit] == NULL) {
            link->next[bit] = (T*)calloc(1, sizeof(T));
        }
        insert(link->next[bit], value, depth - 1);
    }
}

void delete(T* link, int value, int depth) {
    link->cnt--;
    if(depth >= 0) {
        bool bit = value & (1 << depth);
        delete(link->next[bit], value, depth - 1);
    }
}

int maximum(T* link, int x, int depth) {
    bool bit = x & (1 << depth);
    if(link->next[!bit] != NULL && link->next[!bit]->cnt != 0) {
        return maximum(link->next[!bit], x, depth - 1) + (1 << depth);
    }
    else if(link->next[bit] != NULL && link->next[bit]->cnt != 0) {
        return maximum(link->next[bit], x, depth - 1);
    }

    return 0;
}

int main() {
    insert(&sequence, 0, BIT_MAX);

    int M, c, x;
    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &c, &x);
        switch(c) {
            case ADD:
                insert(&sequence, x, BIT_MAX);
                break;

            case REMOVE:
                delete(&sequence, x, BIT_MAX);
                break;
            
            case XOR:
                printf("%d\n", maximum(&sequence, x, BIT_MAX));
                break;
        }
    }
}