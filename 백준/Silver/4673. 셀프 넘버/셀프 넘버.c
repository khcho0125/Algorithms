#include<stdio.h>

int arr[10001] = {0,};

int d(int n) {
    int result = n;
    while(n != 0) {
        result += n % 10;
        n /= 10;
    }
    return result;
}

int main() {
    for(int i = 1; i <= 10000; i++) {
        arr[d(i)] = 1;
    }
    for(int i = 1; i <= 10000; i++) {
        if(!arr[i]) {
            printf("%d\n", i);
        }
    }
}