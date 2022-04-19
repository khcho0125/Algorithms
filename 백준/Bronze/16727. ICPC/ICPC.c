#include<stdio.h>

int main() {

    int N, M, N2, M2;
    scanf("%d %d %d %d", &N, &M2, &M, &N2);
    if(N + N2 > M2 + M) {
        printf("Persepolis");
    } else if(M2 + M > N + N2) {
        printf("Esteghlal");
    } else if(N2 > M2) {
        printf("Persepolis");
    } else if(M2 > N2) {
        printf("Esteghlal");
    } else {
        printf("Penalty");
    }
}
