#include <stdio.h>

int main()
{
    int n, pay, Y = 0, M = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &pay);
        Y += ((pay / 30) + 1) * 10;
        M += ((pay / 60) + 1) * 15;
    }

    if(Y == M) {
        printf("%s %s ", "Y", "M");
    } else {
        printf("%s ", (Y > M ? "M" : "Y"));
    }
    printf("%d", (Y > M ? M : Y));
}
