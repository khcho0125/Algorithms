#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Trie {
    int size;
    struct Trie* next[26];
    bool exist;
}Trie;

char buffer[81];
int cnt = 0;

void save(Trie* link, int p) {
    int idx = buffer[p] - 'a';

    if(link->next[idx] == NULL) {
        link->next[idx] = (Trie*)malloc(sizeof(Trie));

        link->next[idx]->size = 0;
        link->next[idx]->exist = false;
        memset(link->next[idx]->next, 0, sizeof(link->next[idx]->next));

        link->size++;
    }

    if(buffer[p + 1] == '\0') 
        link->next[idx]->exist = true;
    else 
        save(link->next[idx], p + 1);
}

void calculator(Trie* link, int sum) {
    if(link->exist) cnt += sum;

    bool automatic = link->size > 1 || link->exist;

    if (link->size) {
        for(int i = 0; i < 26; i++) {
            if(link->next[i] != NULL) calculator(link->next[i], sum + automatic);
        }
    }

    free(link);
}

void execute(int N, Trie* dict) {

    for(int i = 0; i < N; i++) {
        scanf("%s", buffer);
        save(dict, 0);
    }

    calculator(dict, 0);

    printf("%.2lf\n", (double)cnt / N);
}

int main() {
    int N;
    for(; ~scanf("%d", &N); cnt = 0) {
        Trie* dict = (Trie*)malloc(sizeof(Trie));
        dict->exist = false;
        dict->size = 1;
        memset(dict->next, 0, sizeof(dict->next));

        execute(N, dict);
    }
}