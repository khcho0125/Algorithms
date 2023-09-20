#include<stdio.h>
#include<string.h>

#define N_MAX 1000001

char str[N_MAX];
char ad[N_MAX];
int pi[N_MAX];

void kmp(int n) {
    int begin = 1, matched = 0;
    while(begin + matched < n) {
        if(ad[begin + matched] == ad[matched]) {
            matched++;
            pi[begin + matched - 1] = matched;
        }
        else {
            if(matched == 0) {
                begin++;
            }
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
}

int main() {
    int L, len;
    scanf("%d ", &L);
    gets(str);
    len = strlen(str);

    for(int i = 1; i <= len; i++) {
        ad[len - i] = str[i - 1];
    }

    kmp(len);

    printf("%d", L - pi[len - 1]);
}