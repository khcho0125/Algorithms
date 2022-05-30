#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char T[1000001];
char P[1000001];
int result[1000001] = {0,};
int pre = 0;

int* Matcher(int len) {
    int* search = (int*)malloc(sizeof(int) * len);
    memset(search, 0, sizeof(int) * len);
    int begin = 1, matched = 0;

    while(begin + matched < len) {
        if(P[begin + matched] == P[matched]) {
            matched++;
            search[begin + matched - 1] = matched;
        }
        else {
            if(matched == 0) {
                begin++;
            }
            else {
                begin += matched - search[matched - 1];
                matched = search[matched - 1];
            }
        }
    }

    return search;
}

void KMP() {
    int n = strlen(T);
    int m = strlen(P);

    int* search = Matcher(m);

    int begin = 0, matched = 0;
    
    while(begin <= n - m) {
        if(matched < m && T[begin + matched] == P[matched]) {
            matched++;

            if(matched == m) {
                result[pre++] = begin + 1;
            }
        }
        else {
            if(matched == 0) {
                begin++;
            }
            else {
                begin += matched - search[matched - 1];
                matched = search[matched - 1];
            }
        }
    }
}

int main() {
    gets(T);
    gets(P);
    KMP();
    printf("%d\n", pre);
    for(int i = 0; i < pre; i++) {
        printf("%d ", result[i]);
    }
}