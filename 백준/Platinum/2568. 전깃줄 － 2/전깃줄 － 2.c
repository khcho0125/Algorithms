#include<stdio.h>
#include<stdlib.h>

typedef struct dp {
    int value;
    int idx;
}dp;

int lower = 1;
int list[100001] = { 0, };
dp input[100001];
int watch[100001] = {0,};
int size = 0;

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
    watch[size++] = front;
}

int main() {
    int n, start, i, temp, pre;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d %d", &input[i].value, &input[i].idx);
    }
    qsort(input, n, sizeof(dp), compare);
    for(i = 0; i < n; i++) {
        if(list[lower - 1] < input[i].idx) {
            list[lower++] = input[i].idx;
            watch[size++] = lower - 1;
        }
        else {
            search(input[i].idx);
        }
    }
    printf("%d\n", n - lower + 1);
    temp = n - 1;
    pre = n - lower;
    for(i = lower - 1; temp >= 0; i--) {
        while(temp >= 0) {
            if(watch[temp] == i) {
                temp--;
                break;
            }
            list[pre] = input[temp].value;
            temp--;
            pre--;
        }
    }
    for(i = 0; i < n - lower + 1; i++) {
        printf("%d\n", list[i]);
    }
}