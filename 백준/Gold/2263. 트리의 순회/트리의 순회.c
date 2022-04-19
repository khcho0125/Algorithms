#include<stdio.h>
#include<stdlib.h>

typedef struct baekjoon {
    int idx;
    int value;
}node;

node input[100001] = {0,};
int input2[100001] = {0,};
int pre = 0, N;

int compare(const void* a, const void* b) {
    node num1 = *(node*)a;
    node num2 = *(node*)b;

    if(num1.value > num2.value) {
        return 1;
    }

    if(num1.value < num2.value) {
        return -1;
    }

    return 0;
}

int search(int n) {
    int min = 1, max = N, mid;
    while(min <= max) {
        mid = (min + max) / 2;
        if(input[mid - 1].value >= n) {
            max = mid - 1;
        }
        if(input[mid - 1].value < n) {
            min = mid + 1;
        }
    }
    return input[min - 1].idx;
}

void tree(int start, int end, int count) {
    if(start > end) return;
    printf("%d ", input2[end]);
    if(start == end) return;
    int mid = search(input2[end]) - count;
    tree(start, mid - 1, count);
    tree(mid, end - 1, count + 1);
}

int main() {
    int value;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &input[i].value);
        input[i].idx = i;
    }
    qsort(input, N, sizeof(node), compare);
    for(int i = 0; i < N; i++) {
        scanf("%d", &input2[i]);
    }
    tree(0, N - 1, 0);
}