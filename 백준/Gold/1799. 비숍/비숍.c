#include<stdio.h>

#define max(a, b) ((a > b) ? a : b)

typedef struct Q {
    int x, y;
}Q;

int X[20] = {0,};
int Y[20] = {0,};
int result[2] = {0,};
Q Queue[2][50];
int pre[2] = {0,};
int N;

void tracking(int cnt, int front, int color) {
    result[color] = max(result[color], cnt);
    if(front == pre[color]) 
        return;
    int x = Queue[color][front].x;
    int y = Queue[color][front].y;
    if(!X[x + y - 1] && !Y[y - x + N]) {
        X[x + y - 1] = 1;
        Y[y - x + N] = 1;
        tracking(cnt + 1, front + 1, color);
        X[x + y - 1] = 0;
        Y[y - x + N] = 0;
    }
    tracking(cnt, front + 1, color);
}

int main() {
    int input, front = 0, color;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            scanf("%d", &input);
            if(input) {
                color = (i + j - 1) % 2;
                Queue[color][pre[color]].x = i;
                Queue[color][pre[color]++].y = j;
            }
        }
    }
    tracking(0, 0, 0);
    tracking(0, 0, 1);
    printf("%d", result[0] + result[1]);
}