#include <stdio.h>

int main()
{
    int N, W;
    scanf("%d %d", &N, &W);
    if(N >= W) {
        if(W == 1 || W == 2) {
            printf("NEWBIE!");
        } else {
            printf("OLDBIE!");
        }
    }
    else {
        printf("TLE!");
    }
}