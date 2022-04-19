#include <stdio.h>
#include <stdlib.h>

int arr[2000001] = {0,};

int main() {
    int i, n, input, min, max;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &input);
        if(i == 0) {
            min = input;
            max = input;
        }
        if(min > input) {
            min = input;
        }
        if(max < input) {
            max = input;
        }
        arr[input + 1000000] = 1;
    }
    for(i = min; i < max + 1; i++) {
        if(arr[i + 1000000])
            printf("%d\n", i);
    }
}