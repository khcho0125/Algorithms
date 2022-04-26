#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    int* answer = (int*)malloc(sizeof(int));
    answer[0] = 7;
    answer[1] = 7;
    int number[46] = {0,};
    for(int i = 0; i < lottos_len; i++) {
        number[lottos[i]]++;
    }

    for(int i = 0; i < win_nums_len; i++) {
        if(number[win_nums[i]]) {
            answer[0]--;
            answer[1]--;
        }
    }

    answer[0] -= number[0];
    answer[0] = answer[0] != 7 ? answer[0] : 6;
    answer[1] = answer[1] != 7 ? answer[1] : 6;
    return answer;
}