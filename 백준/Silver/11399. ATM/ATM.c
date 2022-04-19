#include<stdio.h>
#include<stdlib.h>

int main() {
    int T, temp, pre, sum = 0;
    scanf("%d", &T);
    int *arr = (int*)malloc(sizeof(int) * T);
    for(int i = 0; i < T; i++) {
        scanf("%d", &arr[i]);
        pre = i;
        if(i != 0) {
            temp = arr[i];
            while((pre != 0) && arr[pre - 1] > temp) {
                arr[pre] = arr[pre - 1];
                sum -= arr[pre];
                pre--;
            }
            arr[pre] = temp;
        }
        sum += (T - pre) * arr[pre];
    }
    printf("%d", sum);
}