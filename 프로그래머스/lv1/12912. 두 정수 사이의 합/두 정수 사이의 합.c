#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define swap(a, b) {int i = a; a = b; b = i;}

long long solution(int a, int b) {
    long long answer = 0;
    if(a > b) swap(a, b);
    for(int i = a; i <= b; i++) {
        answer += i;
    }
    return answer;
}