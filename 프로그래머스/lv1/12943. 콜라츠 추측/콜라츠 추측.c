#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num) {
    for(int i = 0; i < 500 & num > 0; i++) {
        if(num == 1) return i;
        if(num % 2) num = num * 3 + 1;
        else num /= 2;
    }
    return num == 1 ? 500 : -1;
}