#include<stdio.h>

double score[1000];

int main() {
    int T, N;
    double result, student;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        scanf("%d", &N);
        result = 0, student = 0;
        for(int j = 0; j < N; j++) {
            scanf("%lf", &score[j]);
            result += score[j];
        }
        result /= N;
        for(int j = 0; j < N; j++) {
            if(result < score[j]) {
                student++;
            }
        }
        result = ((double)100 / N) * student;
        printf("%.3lf%%\n", result);
    }
}