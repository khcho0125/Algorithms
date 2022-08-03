#include<stdio.h>

#define max(a, b) ((a) > (b) ? a : b)
#define min(a, b) ((a) < (b) ? a : b)

typedef struct Pair {
    int lower, upper;
}pair;

int A[5000];
pair map[800001];

int main() {
    int N, W, value;
    scanf("%d %d", &W, &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        for(int j = 1; j < i; j++) {
            value = A[i] + A[j];
            if(value >= W) continue;

            if(map[W - value].upper && map[W - value].lower && (map[W - value].upper < j || map[W - value].lower > i)) {
                printf("YES");
                return 0;
            }

            if(!map[value].upper) map[A[i] + A[j]] = (pair){j, i};
            else {
                map[value].upper = min(map[value].upper, i);
                map[value].lower = max(map[value].lower, j);
            }
        }
    }
    
    printf("NO");
}