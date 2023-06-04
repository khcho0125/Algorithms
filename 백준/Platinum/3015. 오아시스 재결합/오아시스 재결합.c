#include <stdio.h>

#define ll long long

typedef struct Map {
    int value;
    int cnt;
} Map;

ll ans = 0;
Map stack[500000] = {0,};
int pre = 0;

int main() {
    int N, value;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &value);

        while (pre != 0 && stack[pre - 1].value < value) {
            ans += stack[--pre].cnt;
        }
        if(!pre) {
            stack[pre].value = value;
            stack[pre++].cnt = 1;
        }
        else if (stack[pre - 1].value == value) {
            ans += (pre - 1 != 0) + stack[pre - 1].cnt++;
        }
        else {
            stack[pre].value = value;
            ans += stack[pre++].cnt = 1;
        }
    }

    printf("%lld", ans);
}