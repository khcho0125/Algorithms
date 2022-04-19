#include<stdio.h>
#include<stdbool.h>

int sosu[283148] = {0,};
int pre = 1;
bool num[4000001] = {0,};

int main() {
    int N, result = 0, temp;
    scanf("%d", &N);
    for(int i = 2; i <= N; i++) {
        if(!num[i]) {
            sosu[pre] = i;
            temp = i;
            for(int j = 1; j <= pre && temp <= N; j++) {
                if(temp == N) {
                    result++;
                    break;
                }
                temp += sosu[pre - j];
            }
            pre++;
            for(int j = i + i; j <= N; j += i) {
                num[j] = true;
            }
        }
    }
    printf("%d", result);
}