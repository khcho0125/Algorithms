#include<stdio.h>

int main() {
    int arr[5], temp = 1, cnt = 0;
    for(int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    while(1) {
        for(int i = 0; i < 5; i++) {
            if(!(temp % arr[i])) {
                cnt++;
            }
        }
        if(cnt >= 3) {
            printf("%d", temp);
            break;
        }
        cnt = 0;
        temp++;
    }   
}