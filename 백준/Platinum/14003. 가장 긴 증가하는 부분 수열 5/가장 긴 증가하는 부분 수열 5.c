#include<stdio.h>

int lower = 1;
int list[1000001] = {-1000000001, 0};
int input[1000000];
int idx[1000000] = {0,};
int prt[1000001] = {0,};

int logN(int n) {
    int front = 1, end = lower, mid;
    while(front <= end) {
        mid = (front + end) / 2;
        if(list[mid] >= n) {
            end = mid - 1;
        }
        else if(list[mid] < n) {
            front = mid + 1;
        }
    }
    list[front] = n;
    return front;
}

int main() {
    int n, start, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &input[i]);
        if((lower == 1) || list[lower - 1] < input[i]) {
            idx[i] = lower;
            list[lower++] = input[i];
        }
        else {
            idx[i] = logN(input[i]); 
        }
    }
    printf("%d\n", lower - 1);
    for(i = lower - 1; i > 0; i--) {
        for(; idx[n - 1] != i; n--);
            prt[i] = input[n - 1];
    }
    for(i = 1; i < lower; i++) {
        printf("%d ", prt[i]);
    }
}