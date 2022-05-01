#include <string.h>
#include <iostream>

#define D(a) (a * a);
#define T(a) (a * a * a);

using namespace std;

int solution(string dartResult) {
    int answer = 0, pre = 0;
    int stack[3];
    for(int i = 0; dartResult[i] != '\0'; i++) {
        if(dartResult[i] >= '0' && dartResult[i] <= '9') {
            if(i && dartResult[i - 1] == '1' && dartResult[i] == '0') {
                stack[pre] = 10;
                continue;
            }
            stack[pre] = dartResult[i] - '0';
        }
        else {
            switch(dartResult[i]) {
                case 'S':
                    stack[pre++] = stack[pre];
                    break;
                case 'D':
                    stack[pre++] = D(stack[pre]);
                    break;
                case 'T':
                    stack[pre++] = T(stack[pre]);
                    break;
                case '*':
                    for(int k = pre - 2; k < pre; k++) {
                        stack[k] *= 2;
                    }
                    break;
                case '#':
                    stack[pre - 1] *= -1;
                    break;
            }
        }
    }
    return answer = stack[0] + stack[1] + stack[2];
}