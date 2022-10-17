#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool prime[3000] = {1, 1};

int solution(int nums[], size_t nums_len) {
    int answer = 0;
    for(int i = 2; i < 55; i++) {
        if(!prime[i]) {
            int temp = i + i;
            while(temp < 3000) {
                prime[temp] = true;
                temp += i;
            }
        }
    }
    for(int i = 0; i < nums_len - 2; i++)
        for(int j = i + 1; j < nums_len - 1; j++)
            for(int k = j + 1; k < nums_len; k++)
                answer += !prime[nums[i] + nums[j] + nums[k]];
    return answer;
}