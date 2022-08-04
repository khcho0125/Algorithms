#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define min(a, b) ((a) < (b) ? a : b)
#define max(a, b) ((a) > (b) ? a : b)

typedef struct Data {
    long long num, len;
}data;

data list[50];

int compare(const void* a, const void* b) {
    data num1 = *(data*)a;
    data num2 = *(data*)b;
    
    unsigned long long one = (unsigned long long)(num1.num * num2.len + num2.num);
    unsigned long long two = (unsigned long long)(num2.num * num1.len + num1.num);
    return one < two;
}

int main() {
    int K, N;
    long long M = 0, len;
    scanf("%d %d", &K, &N);
    for(int i = 0; i < K; i++, len = 1) {
        scanf("%lld", &list[i].num);
        while(list[i].num / len)
            len *= 10;
        list[i].len = len;
        M = max(M, list[i].num);
    }
    qsort(list, K, sizeof(data), compare);
    for(int i = 0; i < K; i++) {
        printf("%lld", list[i].num);
        if(list[i].num == M) {
            for(int j = 0; j < N - K; j++)
                printf("%lld", list[i].num);
            M = 0;   
        }
    }
}