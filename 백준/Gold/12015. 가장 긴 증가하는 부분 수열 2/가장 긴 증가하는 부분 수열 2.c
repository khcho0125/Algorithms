#include<stdio.h>

int lower = 0;
int stack[1000000] = {0,};

void logN(int n) {
    int front = 1, end = lower, mid;
    while(front <= end) {
        mid = (front + end) / 2;
        if(stack[mid - 1] > n) {
            end = mid - 1;
            continue;
        }
        if(stack[mid - 1] < n) {
            front = mid + 1;
            continue;
        }
        if(stack[mid - 1] == n) {
            return;
        }
    }
    stack[front - 1] = n;
}

int main() {
    int n, result = 0, input;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &input);
        if((!lower) || stack[lower - 1] < input) {
            stack[lower++] = input;
        }
        else {
            logN(input);
        }
    }
    printf("%d", lower);
}