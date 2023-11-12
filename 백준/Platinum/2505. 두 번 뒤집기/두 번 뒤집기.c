#include<stdio.h>
#include<stdbool.h>

#define N_MAX 10001

#define min(a, b) ((a) < (b) ? a : b)
#define max(a, b) ((a) > (b) ? a : b)
#define swap(a, b) {int sw_temp = a; a = b; b = sw_temp;}

typedef struct Pair {
    int i, j;
}P;

int arr[N_MAX];

int tb[N_MAX];
int right[N_MAX];
int left[N_MAX];
P result[2];

P findRange(int N, int* array) {
    P result = (P){.i = 1, .j = N};
    while(result.i < N && result.i == array[result.i]) result.i++;
    while(result.i < result.j && result.j == array[result.j]) result.j--;
    return result;
}

bool isAnswer(int s, int e, int* array) {
    for(int i = s; i <= e && i == array[i]; i++) 
        if(i == e) return true;
    return false;
}

void flip(int N) {
    for(int i = 1; i <= N; i++) {
        tb[arr[i]] = i;
        right[i] = left[i] = arr[i];
    }

    P range = findRange(N, arr), next;
    for(int i = range.i, j = tb[range.i]; i < j; i++, j--) swap(left[i], left[j]);

    next = findRange(N, left);
    for(int i = next.i, j = next.j; i < j; i++, j--) swap(left[i], left[j]);

    if(isAnswer(range.i, range.j, left)) {
        result[0] = (P){.i = range.i, .j = tb[range.i]};
        result[1] = (P){.i = next.i, .j = next.j};
        return;
    }

    for(int i = tb[range.j], j = range.j; i < j; i++, j--) swap(right[i], right[j]);

    next = findRange(N, right);
    for(int i = next.i, j = next.j; i < j; i++, j--) swap(right[i], right[j]);

    result[0] = (P){.i = tb[range.j], .j = range.j};
    result[1] = (P){.i = next.i, .j = next.j};
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }

    flip(N);

    for(int t = 0; t < 2; t++) {
        printf("%d %d\n", result[t].i, result[t].j);
    }
}