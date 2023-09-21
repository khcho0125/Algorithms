#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define ll long long
#define S_MAX_LEN 2000001
#define min(a, b) ((a) < (b) ? a : b)

char str[S_MAX_LEN];
char parse[S_MAX_LEN + S_MAX_LEN];

ll A[S_MAX_LEN + S_MAX_LEN];

void manachers(char* s, int len) {
    ll r = 0, p = 0;
    for(int i = 0; i < len; i++) {
        if(i <= r) A[i] = min(A[2 * p - i], r - i);
        else A[i] = 0;

        while(i - A[i] - 1 >= 0 && i + A[i] + 1 < len && s[i - A[i] - 1] == s[i + A[i] + 1]) A[i]++;

        if(r < i + A[i]) {
            r = i + A[i];
            p = i;
        }
    }
}

int main() {
    gets(str);
    int len = strlen(str);

    for(int i = 0; i < len; i++) {
        parse[i * 2 + 1] = str[i];
    }

    manachers(parse, len * 2 + 1);

    ll result = len;
    for(int i = 0; i < len * 2 + 1; i++) {
        result += A[i] / 2;
    }

    printf("%lld", result);
}