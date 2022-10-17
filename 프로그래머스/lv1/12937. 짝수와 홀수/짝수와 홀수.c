#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int num) {
    if(num % 2) return "Odd";
    return "Even";
}