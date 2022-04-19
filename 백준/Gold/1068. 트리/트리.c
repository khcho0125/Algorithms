#include<stdio.h>

int Tree[50][50] = {0,};
int Treepre[50] = {0,};
int Root[50] = {0,};
int Rootpre = 0;

int Counting(int node) {
    int sum = 0;
    if(Treepre[node] == -1) {
        return 0;
    }

    for(int i = 0; i < Treepre[node]; i++) {
        sum += Counting(Tree[node][i]);
    }

    if(sum == 0) {
        sum = 1;
    }
    
    return sum;
}

int main() {
    int N, input, result = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &input);
        if(input == -1) {
            Root[Rootpre++] = i;
        }
        else {
            Tree[input][Treepre[input]++] = i;
        }
    }
    scanf("%d", &input);
    Treepre[input] = -1;
    for(int i = 0; i < Rootpre; i++) {
        result += Counting(Root[i]);
    }
    printf("%d", result);
}