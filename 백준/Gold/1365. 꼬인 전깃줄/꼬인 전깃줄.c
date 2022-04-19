#include<stdio.h>
#include<stdlib.h>

int lower = 1;
int list[100001] = { 0, };
int input[100001];

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
    int n, start, i, temp, pre;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }
    for(i = 0; i < n; i++) {
        if(list[lower - 1] < input[i]) {
            list[lower++] = input[i];
        }
        else {
            search(input[i]);
        }
    }
    printf("%d", n - lower + 1);
}