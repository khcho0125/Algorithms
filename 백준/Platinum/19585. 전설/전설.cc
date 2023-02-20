#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<map>

#define COLOR_EXIST 4
#define NICKNAME_EXIST 8

using namespace std;

typedef struct Trie {

    /*
        0x01 - color
        0x02 - nickname
        0x04 - color_exist
        0x08 - nickname_exist
    */
    int judge;
    map<char, Trie*> next;
}Trie;

enum Type { 
    COLOR = 1,
    NICKNAME = 2
};

char buffer[2000];
bool judgement[2000];

Trie dict;

Trie* makeNext() {
    Trie* next = new Trie();
    next->judge = 0;

    return next;
}

void insert_color(Trie* link, int idx) {

    link->judge |= COLOR;

    if(buffer[idx] == '\0') {
        link->judge |= COLOR_EXIST;
        return;
    }

    if(link->next.count(buffer[idx]) == 0) {
        link->next.insert(make_pair(buffer[idx], makeNext()));
    }

    insert_color(link->next[buffer[idx]], idx + 1);
}

void insert_nickname(Trie* link, int idx) {

    link->judge |= NICKNAME;

    if(idx < 0) {
        link->judge |= NICKNAME_EXIST;
        return;
    }

    if(link->next.count(buffer[idx]) == 0) {
        link->next.insert(make_pair(buffer[idx], makeNext()));
    }

    insert_nickname(link->next[buffer[idx]], idx - 1);
}

void select_color(Trie* link, int idx) {

    if(!(link->judge & COLOR)) return;

    if(link->judge & COLOR_EXIST) judgement[idx - 1] = true;

    if(buffer[idx] != '\0' && link->next.count(buffer[idx])) select_color(link->next[buffer[idx]], idx + 1);
}

bool select_nickname(Trie* link, int idx) {
    if(!((link->judge & NICKNAME))) return false;

    if(judgement[idx] && (link->judge & NICKNAME_EXIST)) return true;

    if(idx != 0 && link->next.count(buffer[idx])) return select_nickname(link->next[buffer[idx]], idx - 1);

    return false;
}

int main() {
    int C, N, Q;
    scanf("%d %d", &C, &N);
    for(int i = 0; i < C; i++) {
        scanf("%s", buffer);
        insert_color(&dict, 0);
    }

    for(int i = 0; i < N; i++) {
        scanf("%s", buffer);
        insert_nickname(&dict, strlen(buffer) - 1);
    }

    scanf("%d", &Q);
    for(int i = 0; i < Q; i++) {
        scanf("%s", buffer);

        select_color(&dict, 0);
        printf(select_nickname(&dict, strlen(buffer) - 1) ? "Yes\n" : "No\n");

        memset(judgement, 0, sizeof(judgement));
    }
}