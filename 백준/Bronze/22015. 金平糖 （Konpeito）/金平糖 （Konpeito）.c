#include <stdio.h>

int main()
{
    int N, sum = 0, max = 0;
    for(int i = 0; i < 3; i++) {
        scanf("%d", &N);
        if(max < N) {
            max = N;
        }
        sum += N;
    }
    printf("%d", max * 3 - sum);
}