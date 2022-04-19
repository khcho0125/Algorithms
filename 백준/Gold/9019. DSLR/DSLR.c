#include<stdio.h>
#include<string.h>

char command[10000][2500] = {0,};
int queue[10000] = {0,};
int visit[10000] = {0,};
int front = 0, back = 0;

int func(int M) {
    int N, temp;
    while(front < back) {
        N = queue[front++];
        if(N == M) {
            printf("%s\n", command[N]);
            memset(queue, 0, sizeof(int) * 10000);
            memset(visit, 0, sizeof(int) * 10000);
            break;
        }
        temp = (N * 2) % 10000;
        if(!visit[temp]) {
            strcat(strcpy(command[temp], command[N]), "D");
            queue[back++] = temp;
            visit[temp] = 1;
        }
        temp = N > 0 ? N - 1 : 9999;
        if(!visit[temp]) {
            strcat(strcpy(command[temp], command[N]), "S");
            queue[back++] = temp;
            visit[temp] = 1;
        }
        temp = (N % 1000) * 10 + N / 1000;
        if(!visit[temp]) {
            strcat(strcpy(command[temp], command[N]), "L");
            queue[back++] = temp;
            visit[temp] = 1;
        }
        temp = (N % 10) * 1000 + N / 10;
        if(!visit[temp]) {
            strcat(strcpy(command[temp], command[N]), "R");
            queue[back++] = temp;
            visit[temp] = 1;
        }
    }
}

int main() {
    int T, N, M;
    scanf("%d", &T);
    for(int i = 0; i < T; i++, front = 0, back = 0) {
        scanf("%d %d", &N, &M);
        queue[back++] = N; 
        command[N][0] = '\0';
        visit[N] = 1;
        func(M);
    }
}