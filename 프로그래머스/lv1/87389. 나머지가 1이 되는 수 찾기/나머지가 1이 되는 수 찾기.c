#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int i = 1;
    for(; i < n && n % i != 1; i++);
    return i;
}