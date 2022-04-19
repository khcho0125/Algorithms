#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b) {

    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if(num1 > num2) {
        return -1;
    }

    if(num1 < num2) {
        return 1;
    }

    return 0;
}

int compare2(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if(num1 > num2) {
        return 1;
    }

    if(num1 < num2) {
        return -1;
    }

    return 0;
}

int Max_sum(int a, int b) {
    return a * b > a + b ? a * b : a + b;
}

int main() {
    int N, input, un = 0, up = 0, result = 0;
    scanf("%d", &N);
    int *upper = (int*)malloc(sizeof(int) * N);
    int *under = (int*)malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &input);
        if(input > 0) {
            upper[up++] = input;
        }
        else {
            under[un++] = input;
        }
    }
    qsort(upper, up, sizeof(int), compare2);
    qsort(under, un, sizeof(int), compare);
    for(up--; 0 < up; up -= 2) {
        result += Max_sum(upper[up - 1], upper[up]);
    }
    for(un--; 0 < un; un -= 2) {
        result += Max_sum(under[un - 1], under[un]);
    }
    if(!up) {
        result += upper[up];
    }
    if(!un) {
        result += under[un];
    }
    printf("%d", result);
}