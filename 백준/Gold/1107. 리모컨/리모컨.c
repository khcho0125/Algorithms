#include<stdio.h>
#include<stdbool.h>

#define abs(a) ((a) < 0 ? (a) * -1 : a)
#define min(a, b) ((a) < (b) ? a : b)

bool remote[10];

int broken(int N) {
    int len = 0;
    do {
        if (remote[N % 10]) return false;
        N /= 10;
        len++;
    } while(N);

    return len;
}

int main() {
    int channel, M, button;
    scanf("%d %d", &channel, &M);
    for(int i = 0; i < M; i++) {
        scanf("%d", &button);
        remote[button] = true;
    }

    int least = abs(channel - 100);

    for(int i = 0; i <= 1000000; i++) {
        int len = broken(i);

        if (len) {
            least = min(least, len + abs(channel - i));
        }

    }

    printf("%d", least);
}