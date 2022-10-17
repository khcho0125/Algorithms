#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int measure[1001] = {0,};

int solution(int left, int right) {
    int temp, answer = 0;
    for(int i = 1; i <= right; i++) {
        temp = i;
        while(temp <= right) {
            measure[temp]++;
            temp += i;
        }
    }
    for(int i = left; i <= right; i++) {
        answer += i * (measure[i] % 2 ? -1 : 1);
    }
    return answer;
}