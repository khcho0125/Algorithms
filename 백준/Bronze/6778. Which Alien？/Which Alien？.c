#include<stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    if(N > 2 && M < 5) 
        printf("TroyMartian\n");
    if(N < 7 && M > 1) 
        printf("VladSaturnian\n");
    if(N < 3 && M < 4) 
        printf("GraemeMercurian\n");
}