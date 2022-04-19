#include<stdio.h>
int main() {
    int N, M, T;
    scanf("%d %d %d", &N, &M, &T);
    for(int i = 0, sum = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(sum == T) {
                printf("%d %d", i, j);
                return 0;
            }
            sum++;
        }
    }    
}