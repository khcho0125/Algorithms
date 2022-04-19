#include<stdio.h>

int node[10][2] = {
    {1, 3},
    {2, 0},
    {-1, -1},
    {4, 2},
    {5, 2},
    {5, 6},
    {7, 8},
    {2, 0},
    {9, 8},
    {5, 0}
};

char str[201];

void func(int idx, int state) {
    if(state == 2 || (str[idx] == '\0' && (state == 1 || state == 3 || state == 4 || state == 5 || state == 7 || state == 9))) {
        printf("NO\n");
        return;
    }

    if(str[idx] == '\0') {
        printf("YES\n");
        return;
    }

    func(idx + 1, node[state][str[idx] - '0']);
}

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        scanf("%s", str);
        func(0, 0);
    }
}