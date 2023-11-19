#include<stdio.h>

#define N_MAX 1000000

int numbers[N_MAX + 1];

int find(int x) {
    if(!numbers[x]) return x;
    return numbers[x] = find(numbers[x]);
}

void Union(int u, int v) {
    int vroot = find(v);
    numbers[u] = vroot;
}

void pretreatment() {
    int size = N_MAX / 2;
    for(int i = 2; i <= N_MAX; i += 2) numbers[i] = i + 1;

    for(int k = 3, i = 2; k <= size; k = find(k + 1), i++) {
        for(int temp = k, j = i; temp <= N_MAX; temp = find(temp + 1), j++) {
            if(j % k == 0) {
                Union(temp, temp + 1);
                size--;
            }
        }
    }
}

int main() {
    pretreatment();

    int T, N;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        printf(numbers[N] ? "unlucky\n" : "lucky\n");
    }
}