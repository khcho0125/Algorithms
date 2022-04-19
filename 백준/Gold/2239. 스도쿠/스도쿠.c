#include<stdio.h>

typedef struct Queue {
    int x, y, z;
}Q;

int X[10] = {0,};
int Y[10] = {0,};
int Z[10] = {0,};

Q queue[82] = {0,};
int back = 0, finish = 0;
int map[10][10] = {0,};

void tracking(int front) {
    if(front == back) {
        int max = (1 << 9) - 1;
        for(int i = 1; i < 10; i++) {
            if(X[i] != max || Y[i] != max || Z[i] != max) {
                return;
            }
        }
        finish = 1;
        return;
    }

    int x = queue[front].x;
    int y = queue[front].y;
    int z = queue[front].z;
    int num = X[x] | Y[y] | Z[z];
    if(num == (1 << 9) - 1) {
        return;
    }
    for(int i = 1; i < 10 && !finish; i++) {
        if(!(num & 1)) {
            map[x][y] = i;
            X[x] = X[x] | (1 << (i - 1));
            Y[y] = Y[y] | (1 << (i - 1));
            Z[z] = Z[z] | (1 << (i - 1));
            tracking(front + 1);
            X[x] = X[x] & ~(1 << (i - 1));
            Y[y] = Y[y] & ~(1 << (i - 1));
            Z[z] = Z[z] & ~(1 << (i - 1));
        }
        num = num >> 1;
    }
}

int main() {
    int input, z;
    for(int i = 1; i < 10; i++) {
        for(int j = 1; j < 10; j++) {
            scanf("%1d", &map[i][j]);
            z = (j / 3 + (j % 3 != 0)) + (i / 3 + (i % 3 != 0) - 1) * 3;
            if(map[i][j]) {
                X[i] = X[i] | (1 << (map[i][j] - 1));
                Y[j] = Y[j] | (1 << (map[i][j] - 1));
                Z[z] = Z[z] | (1 << (map[i][j] - 1));
            }
            else {
                queue[back].x = i;
                queue[back].y = j;
                queue[back++].z = z;
            }
        }
    }
    if(back != 0) {
        tracking(0);
    }
    for(int i = 1; i < 10; i++) {
        for(int j = 1; j < 10; j++) {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
}