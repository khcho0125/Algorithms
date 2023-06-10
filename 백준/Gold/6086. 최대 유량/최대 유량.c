#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_V 52
#define MAX_E 700
#define INF 987654321

#define min(a, b) ((a) < (b) ? a : b)

int capacity[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];
int layer[MAX_V];
int work[MAX_V];

int queue[MAX_E];
int front, back;

int number(const char x) {
    if (x < 'a') return x - 'A';
    return x - 'a' + 26;
}

bool BFS(int source, int sink) {
    memset(layer, -1, sizeof(layer));
    front = back = 0;
    
    queue[back++] = source;
    layer[source] = 0;
    
    while(front < back) {
        int idx = queue[front++];

        for(int next = 0; next < MAX_V; next++) {
            if(layer[next] == -1 && capacity[idx][next] - flow[idx][next] > 0) {
                layer[next] = layer[idx] + 1;
                queue[back++] = next;
            }
        }
    }

    return layer[sink] != -1;
}

int DFS(int idx, int amount, int sink) {
    if (idx == sink) {
        return amount;
    }

    for(; work[idx] < MAX_V; work[idx]++) {
        if(layer[work[idx]] == layer[idx] + 1 && capacity[idx][work[idx]] - flow[idx][work[idx]] > 0) {
            int result = DFS(work[idx], min(amount, capacity[idx][work[idx]] - flow[idx][work[idx]]), sink);

            if (result > 0) {
                flow[idx][work[idx]] += result;
                flow[work[idx]][idx] -= result;

                return result;
            }
        }
    }
    
    return 0;
}

int Dinitz(int source, int sink) {
    int maxflow = 0;
    while(BFS(source, sink)) {
        memset(work, 0, sizeof(work));

        while(true) {
            int value = DFS(source, INF, sink);
            
            if (!value) break;

            maxflow += value;
        }
    }
    return maxflow;
}

int main() {
    char ai, bi;
    int N, W, A, B, S, T;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf(" %c %c %d", &ai, &bi, &W);

        A = number(ai);
        B = number(bi);

        capacity[A][B] += W;
        capacity[B][A] += W;
    
    }

    printf("%d", Dinitz(0, 25));
}