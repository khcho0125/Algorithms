#include<stdio.h>
#include<stdlib.h>

typedef struct dp {
    int value;
    int idx;
}dp;

int lower = 1;
int list[1000001] = { 0, };
dp input[1000001];

int compare(const void* a, const void* b) {

    dp num1 = *(dp*)a;
    dp num2 = *(dp*)b;

    if(num1.value > num2.value) {
        return 1;
    }

    if(num1.value < num2.value) {
        return -1;
    }

    if(num1.idx <= num2.idx) {
        return 1;
    }
    else {
        return -1;
    }
}

void search(int n) {
    int front = 1, end = lower, mid;
    while(front <= end) {
        mid = (front + end) / 2;
        if(list[mid] > n) {
            end = mid - 1;
        }
        else if(list[mid] < n) {
            front = mid + 1;
        }
        else if(list[mid] == n) {
            return;
        }
    }
    list[front] = n;
}

int main() {
    int n, start, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d %d", &input[i].value, &input[i].idx);
    }
    qsort(input, n, sizeof(dp), compare);
    for(i = 0; i < n; i++) {
        if(list[lower - 1] < input[i].idx) {
            list[lower++] = input[i].idx;
        }
        else {
            search(input[i].idx);
        }
    }
    printf("%d", n - lower + 1);
}