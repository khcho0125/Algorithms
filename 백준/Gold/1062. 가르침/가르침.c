#include<stdio.h>

#define max(a, b) (a > b ? a : b)

int string[50] = {0,};
int result = 0, N;

void tracking(int bit, int learn, int last) {
    if(learn == 0) {
        int count = 0;
        for(int i = 0; i < N; i++) {
            count += (~bit & string[i] ? 0 : 1);
        }
        result = max(result, count);
        return;
    }
    
    for(int i = last; i < 26; i++) {
        if(~bit & 1 << i) {
            tracking(bit | 1 << i, learn - 1, i + 1);
        }
    }
}

int main() {
    int temp = 532741; // a, c, i, n, t
    int K;
    char input[16];
    scanf("%d %d", &N, &K);
    if(K >= 5) {
        for(int i = 0; i < N; i++) {
            scanf("%s", input);
            for(int len = 0; input[len] != '\0'; len++) {
                string[i] |= 1 << (input[len] - 'a');
            }
        }
        tracking(temp, K - 5, 1);
    }
    printf("%d", result);
}