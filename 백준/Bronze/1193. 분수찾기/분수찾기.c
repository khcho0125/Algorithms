#include<stdio.h>

int main() {
    int n, end = 1, start = 0, w = 1, turn = 1;
    scanf("%d", &n);
    while(n > end) {
        start = end;
        w *= -1;
        end += ++turn;
    }
    if(w == -1) {
        n -= start;
        printf("%d/%d", n, turn + 1 - n);
    }
    else {
        n -= start;
        printf("%d/%d", turn + 1 - n, n);
    }
}