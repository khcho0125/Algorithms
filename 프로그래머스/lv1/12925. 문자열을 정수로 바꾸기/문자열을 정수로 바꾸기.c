#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    bool p = false;
    int answer = 0;
    if(s[0] == '-') {
        p = true;
    }
    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] <= '9' && s[i] >= '0') {
            answer *= 10;
            answer += (s[i] - '0');
        }
    }
    if(p) {
        answer *= -1;
    }
    return answer;
}