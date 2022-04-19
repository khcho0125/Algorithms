#include<stdio.h>

#define INF 987654321
#define min(a, b) ((a < b) ? a : b)

int map[10] = {0,};
int test[10];
int pushx[5] = {0, -1, 0, 1, 0};
int pushy[5] = {0, 0, -1, 0, 1};

int btn(int x, int y) {
    int f, s, sum = 0;
    for(int i = 0; i < 5; i++) {
        f = x + pushx[i];
        s = y + pushy[i];

        if(0 <= f && f <= 9 && 0 <= s && s <= 9) {
            test[f] ^= (1 << s);
        }
    }
    return sum;
}

int main() {
    char input;
    int result = INF;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            scanf(" %c", &input);
            if(input == 'O') {
                map[i] = map[i] | (1 << (9 - j));
            }
        }
    }
    for(int c = (2 << 10) - 1; c >= 0; c--) {
        
        int cnt = 0;

        for(int i = 0; i < 10; i++) {
            test[i] = map[i];
        }

        for(int i = 0; i < 10; i++) {
            if(c & (1 << i)) {
                btn(0, i);
                cnt++;
            }
        }

        for(int i = 1; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                if(test[i - 1] & (1 << (9 - j))) {
                    btn(i, (9 - j));
                    cnt++;
                }
            }
        }

        if(test[9] == 0) {
            result = min(result, cnt);
        }

    }
    
    if(result == INF) {
        printf("-1");
    }
    else {
        printf("%d", result);
    }
}