#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n) {
    int* answer = (int*)calloc(n * (n+1) / 2, sizeof(int));

    int num = 1, idx = 0, depth = 0;
    for(int i = n; i > 0; i-=3, depth += 2) {
        idx += depth;
        
        for(int j = 1; j <= i; j++) {
            answer[idx] = num++;
            if(j != i) 
                idx += j + depth;
        }
        for(int j = 0; j < i - 1; j++) {
            answer[++idx] = num++;
        }
       
        for(int j = i; j > 2; j--) {
            answer[idx -= (j + depth)] = num++;
        }
    }

    return answer;
}