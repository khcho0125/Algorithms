#include <stdio.h>

int N;
int arr[100][100] = {
    0,
};

int bacon[100][100] = {
    0,
};

int queue[5000] = {
    0,
};
int queuefront = 0;
int queueback = 0;

void BFS(int data, int V, int idx)
{
    int have = 0, i;
    queue[queuefront] = 0;
    queuefront++;
    for (i = 0; i < N; i++)
    {
        if (data != i && arr[V][i] && (bacon[data][i] > idx || !bacon[data][i]))
        {
            queue[queueback] = i;
            queueback++;
            bacon[data][i] = idx;
            BFS(data, queue[queuefront], idx + 1);
        }
    }
}

int main()
{
    int M, A, B, result, temp, sum, max, i, j, idx;
    scanf("%d %d", &N, &M);
    for (i = 0; i < M; i++)
    {
        scanf("%d %d", &A, &B);
        arr[A - 1][B - 1] = 1;
        arr[B - 1][A - 1] = 1;
    }
    for (i = 0; i < N; i++)
    {
        queue[queueback] = i;
        queueback++;
        BFS(i, i, 1);
        for (j = 0; j < N; j++)
        {
            queue[j] = 0;
        }
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0, sum = 0; j < N; j++)
        {
            sum += bacon[i][j];
        }
        if (sum < max || !i)
        {
            max = sum;
            result = i + 1;
        }
    }
    printf("%d", result);
}