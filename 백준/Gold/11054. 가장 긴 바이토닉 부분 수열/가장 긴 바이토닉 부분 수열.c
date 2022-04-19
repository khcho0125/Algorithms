#include<stdio.h>
#include<string.h>

int lower = 0;
int list[1000] = {0,};
int memory[1000] = {0,};

int max(int a, int b) {
    return a > b ? a : b;
}

void logN(int n) {
    int front = 1, end = lower, mid;
    while(front <= end) {
        mid = (front + end) / 2;
        if(list[mid - 1] > n) {
            end = mid - 1;
            continue;
        }
        if(list[mid - 1] < n) {
            front = mid + 1;
            continue;
        }
        if(list[mid - 1] == n) {
            return;
        }
    }
    list[front - 1] = n;
}

int main() {
    int n, result = 0;
    int input[1000];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
        if((!lower) || list[lower - 1] < input[i]) {
            list[lower++] = input[i];
        }
        else {
            logN(input[i]);
        }
        memory[i] = lower;
    }
    memset(list, 0, n);
    lower = 0;
    for(int i = 1; i <= n; i++) {
        if((!lower) || list[lower - 1] < input[n - i]) {
            list[lower++] = input[n - i];
        }
        else {
            logN(input[n - i]);
        }
        result = max(result, memory[n - i] + lower - 1);
    }
    printf("%d", result);
}