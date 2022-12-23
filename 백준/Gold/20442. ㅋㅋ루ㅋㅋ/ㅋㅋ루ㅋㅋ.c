#include<stdio.h>
#include<string.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

char str[3000000];
int result = 0;
int R = 0;

void compare(int r, int l) {
    int value = R + min(r, l) * 2;

    result = max(result, value);
}

void find(int start, int end, int r, int l) {
    if (start > end) return;

    if(start == end) {
        R++;
        compare(r, l);
        return;
    }

    int rK = r, lK = l, RR = 0;

    if(r <= l) {
        for(; start <= end && str[start] != 'K'; start++, RR++);
        for(; start <= end && str[start] != 'R'; start++, rK++);
    }
    else {
        for(; start <= end && str[end] != 'K'; end--, RR++);
        for(; start <= end && str[end] != 'R'; end--, lK++);
    }

    find(start, end, rK, lK);

    R += RR;
    compare(r, l);
}

int main() {
    scanf("%s", str);
    int len = strlen(str);

    int start = 0, end = len - 1, rK, lK;

    for(rK = 0; start <= end && str[start] != 'R'; start++, rK++);
    for(lK = 0; start <= end && str[end] != 'R'; end--, lK++);

    find(start, end, rK, lK);

    printf("%d", result);
}