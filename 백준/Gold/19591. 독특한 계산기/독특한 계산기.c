#include<stdio.h>
#include<string.h>

char str[1000001];
long long number[500000] = {0,};
char stack[500000] = {0,};
int front = 0, back = 0;
int pre = 0, temp = 0;

long long solve(char str, long long v1, long long v2) {
    switch(str) {
        case '*':
            return v1 * v2;
        case '/':
            return v1 / v2;
        case '+':
            return v1 + v2;
        case '-':
            return v1 - v2;
    }
}

int main() {
    long long ten = 1;
    scanf("%s", str);
    int len = strlen(str);
    for(int i = len - 1; i >= 0; i--) {
        if(i == 0 && str[i] == '-') {
            number[back] *= -1;
        }
        else if(str[i] >= '0' && str[i] <= '9') {
            number[back] += (str[i] - '0') * ten;
            ten *= 10;
        }
        else {
            stack[temp++] = str[i];
            ten = 1;
            back++;
        }
    }
    int idx = temp;
    for(int i = 0; i < idx; i++) {
        long long first = solve(stack[pre], number[front + 1], number[front]);
        long long second = solve(stack[temp - 1], number[back], number[back - 1]);
        if((stack[temp - 1] == '*' || stack[temp - 1] == '/') && (stack[pre] == '-' || stack[pre] == '+')) {
            number[back] = 0;
            number[--back] = second;
            temp--;
        }
        else if((stack[pre] == '*' || stack[pre] == '/') && (stack[temp - 1] == '-' || stack[temp - 1] == '+')) {
            number[front] = 0;
            number[++front] = first;
            pre++;
        }
        else if (first <= second) {
            number[back] = 0;
            number[--back] = second;
            temp--;
        }
        else {
            number[front] = 0;
            number[++front] = first;
            pre++;
        }
    }
    printf("%lld", number[back]);
}