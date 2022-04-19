#include <stdio.h>

int main()
{
    int N, M, input;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%d", &input);
        }
    }
    if(N >= 8) printf("satisfactory");
    else printf("unsatisfactory");
}