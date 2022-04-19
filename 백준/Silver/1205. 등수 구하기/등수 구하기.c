#include<stdio.h>
#include<stdlib.h>

int main() {
    int N, M, P, i, count = 1, same = 0;
    scanf("%d %d %d", &N, &M, &P);
    int* List = (int*)malloc(sizeof(int) * N);
    for(i = 0; i < N; i++) {
        scanf("%d", &List[i]);
    }
    for(i = 0; i < N; i++) {
        if(List[i] > M) {
            count++;
        } else if(List[i] == M) {
            same++;
        }
    }
    if(count + same > P) {
        printf("-1");
    } else {
        printf("%d", count);
    }
}