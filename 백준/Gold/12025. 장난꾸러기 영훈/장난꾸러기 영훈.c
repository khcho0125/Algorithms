#include<stdio.h>
#define ll long long

int password[61];
int queue[61];
int len = 0, pre = 0;

int main() {
    char input;
    ll K;
    scanf("%c", &input);
    for(; input != '\n'; len++) {
        password[len] = input - '0';
        if(password[len] == 1 || password[len] == 2) {
            queue[pre++] = len;
        }
        else if(password[len] == 6) {
            password[len] = 1;
            queue[pre++] = len;
        }
        else if(password[len] == 7) {
            password[len] = 2;
            queue[pre++] = len;
        }
        scanf("%c", &input);
    }
    scanf("%lld", &K);
    K--;
    if(K > (1LL << pre) - 1 || K < 0) {
        printf("-1");
        return 0;
    }
    ll temp = 1;
    for(int i = 1; i <= pre; i++, temp = (temp << 1)) {
        if(K & temp) {
            
            if(password[queue[pre - i]] == 1) {
                password[queue[pre - i]] = 6;
            }
            else {
                password[queue[pre - i]] = 7;
            }
        }
    }
    for(int i = 0; i < len; i++) {
        printf("%d", password[i]);
    }
}