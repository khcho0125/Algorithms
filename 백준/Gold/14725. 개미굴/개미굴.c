#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define min(a, b) (a < b ? a : b)

typedef struct string {
    char input[15][16];
    int len[15];
    int k;
}string;

string input[1000];

int compare(const void* a, const void* b) {
    string str1 = *(string*)a;
    string str2 = *(string*)b;

    int K = min(str1.k, str2.k);
    for(int i = 0; i < K; i++) {
        int len = min(str1.len[i], str2.len[i]);
        for(int j = 0; j < len; j++) {
            if(str1.input[i][j] != str2.input[i][j]) {
                return str1.input[i][j] > str2.input[i][j];
            }
        }
        if(str1.len[i] != str2.len[i]) {
            return str1.len[i] > str2.len[i];
        }
    }
    
    return str1.k > str2.k;
} 

void print(int N) {
    for(int i = 0; i < N; i++) {
        int distinct = 1;
        for(int k = 0; k < input[i].k; k++) {
            if(i == 0 || !distinct || strcmp(input[i - 1].input[k], input[i].input[k])) {
                distinct = 0;
                for(int jump = 0; jump < k; jump++) {
                    printf("--");
                }
                printf("%s\n", input[i].input[k]);
            }
        }
    }
}

int main() {
    int N, K;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &K);
        for(int j = 0; j < K; j++) {
            scanf("%s", input[i].input[j]);
            input[i].len[j] = strlen(input[i].input[j]);
        }
        input[i].k = K;
    }
    qsort(input, N, sizeof(string), compare);
    print(N);
}