#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {

    long long num1 = *(long long*) a;
    long long num2 = *(long long*) b;

    if(num1 > num2) {
        return 1;
    }

    if(num1 < num2) {
        return -1;
    }

    return 0;
}

int main() {
    long long X;
    int N, result = 0, pre = 0;
    scanf("%d %lld", &N, &X);
    long long *queue = (long long*)malloc(sizeof(long long) * N);
    for(int i = 0; i < N; i++) {
        scanf("%lld", &queue[i]);
    }
    int end = N - 1;
    qsort(queue, N, sizeof(long long), compare);
    for(; pre <= end; end--, result++, N--) {
        if(queue[end] != X) {
            break;
        }
    }
    while(pre < end) {
        if((queue[pre] + queue[end]) * 2 >= X) {
            end--;
            pre++;
            N -= 2;
            result++;
        }
        else {
            pre++;
        }
    }
    printf("%d", result + N / 3);
    free(queue);
}