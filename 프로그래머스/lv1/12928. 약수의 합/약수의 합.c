#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) sum += i;
    }
    return sum;
}