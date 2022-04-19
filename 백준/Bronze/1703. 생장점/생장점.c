#include<stdio.h>

int main() {
    int n, g, k, sumg, sumk;
    do {
        sumg = 1;
        sumk = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &g, &k);
            sumg *= g;
            sumk *= g;
            sumk += k;
        }
        if(n != 0) {
            printf("%d\n", sumg - sumk);
        }
    }while(n != 0);
}