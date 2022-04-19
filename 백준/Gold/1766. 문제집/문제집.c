#include <stdio.h>
#include <stdlib.h>

typedef struct V
{
    int idx;
    struct V *link;
} V;

typedef struct tree
{
    int cnt;
    V *link;
    V *back;
} T;

T tree[32000];

int heap[32001] = {
    0,
};
int pre = 1;

void Q_I(int N)
{
    int idx = pre++;
    while (idx != 1 && heap[idx / 2] > N)
    {
        heap[idx] = heap[idx / 2];
        idx /= 2;
    }
    heap[idx] = N;
}

int Q_O()
{
    int first = heap[1];
    int temp = heap[--pre];
    int child = 2, parent = 1;
    while (child <= pre)
    {
        if (child < pre && heap[child] > heap[child + 1])
        {
            child++;
        }

        if (heap[child] > temp)
        {
            break;
        }
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return first;
}

void sort(int N)
{
    V *query = (V *)malloc(sizeof(V));
    int temp;
    for (int i = 0; i < N; i++)
    {
        if (!tree[i].cnt)
        {
            Q_I(i);
        }
    }
    for (int i = 0; i < N; i++)
    {
        temp = Q_O();
        printf("%d ", temp + 1);
        query = tree[temp].link;
        while (query != NULL)
        {
            tree[query->idx].cnt--;
            if (!tree[query->idx].cnt)
            {
                Q_I(query->idx);
            }
            query = query->link;
        }
    }
}

int main()
{
    int N, M, A, B;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        tree[i].link = NULL;
        tree[i].cnt = 0;
    }
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &A, &B);
        V *infor = (V *)malloc(sizeof(V));
        infor->idx = B - 1;
        infor->link = NULL;
        tree[B - 1].cnt++;
        if (tree[A - 1].link == NULL)
        {
            tree[A - 1].link = infor;
            tree[A - 1].back = infor;
        }
        else
        {
            tree[A - 1].back->link = infor;
            tree[A - 1].back = infor;
        }
    }
    sort(N);
}