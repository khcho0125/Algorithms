#include<stdio.h>

int main() {
    int i, n, temp, max = 0, result = 0;
    int weight[1001] = {0,};
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &temp);
        weight[temp]++;
        if(max < temp) {
            max = temp;
        }
    }
    weight[1] = 0;
    for(int i = 2; i < max + 1; i++) {
        for(int j = i + i; j < max + 1; j += i) {
            weight[j] = 0;
        }
        result += weight[i];
    }
    printf("%d", result);
}