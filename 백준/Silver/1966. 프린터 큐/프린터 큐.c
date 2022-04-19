#include<stdio.h>

int main() {
    int Case, pre, n, m, temp, result;
    int weight[10] = {0,};
    scanf("%d", &Case);
    for(int i = 0; i < Case; i++) {
        result = 0;
        pre = 0;
        scanf("%d %d", &n, &m);
        int Queue[n];
        for(temp = 0; temp < n; temp++) {
            scanf("%d", &Queue[temp]);
            weight[Queue[temp]]++;
        }
        for(temp = 0; temp < 9; temp++) {
            while(weight[9 - temp] != 0) {
                if(Queue[pre] == 9 - temp) {
                    result++;
                    weight[9 - temp]--;
                    if(pre == m) {
                        printf("%d\n", result);
                        break;
                    }
                }
                pre++;
                if(pre == n) {
                    pre = 0;
                }
            }
        }
        for(int j = 0; j < 10; j++) {
            weight[j] = 0;
        }
    }
}