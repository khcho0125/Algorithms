#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(long long price, long long money, long long count) {
    long long A = (count + 1) * price;
    long long answer = A * (count / 2) + (count % 2 ? A / 2 : 0) - money;
    return answer < 0 ? 0 : answer;
}