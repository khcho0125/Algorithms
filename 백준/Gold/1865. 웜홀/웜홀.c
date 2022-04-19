#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int idx;
    long long weight;
    struct Node *link;
} node;

typedef struct Tree
{
    node *link;
    node *back;
} tree;

long long dist[500] = {
    0,
};
tree graf[500];

int Bellman(int N)
{
    node *temp = (node *)malloc(sizeof(node));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (temp = graf[j].link; temp != NULL; temp = temp->link)
            {
                if (dist[temp->idx] > temp->weight + dist[j])
                {
                    dist[temp->idx] = temp->weight + dist[j];
                    if (i == N - 1)
                        return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    int N, M, start, end, W, TC;
    long long weight;
    scanf("%d", &TC);
    for (int C = 0; C < TC; C++)
    {
        scanf("%d %d %d", &N, &M, &W);
        for (int i = 0; i < M; i++)
        {
            scanf("%d %d %lld", &start, &end, &weight);
            node *newNode = (node *)malloc(sizeof(node));
            newNode->idx = end - 1;
            newNode->weight = weight;
            newNode->link = NULL;
            if (graf[start - 1].link == NULL)
            {
                graf[start - 1].link = newNode;
                graf[start - 1].back = newNode;
            }
            else
            {
                graf[start - 1].back->link = newNode;
                graf[start - 1].back = newNode;
            }
            node *newNode2 = (node *)malloc(sizeof(node));
            newNode2->idx = start - 1;
            newNode2->weight = weight;
            newNode2->link = NULL;
            if (graf[end - 1].link == NULL)
            {
                graf[end - 1].link = newNode2;
                graf[end - 1].back = newNode2;
            }
            else
            {
                graf[end - 1].back->link = newNode2;
                graf[end - 1].back = newNode2;
            }
        }
        for (int i = 0; i < W; i++)
        {
            scanf("%d %d %lld", &start, &end, &weight);
            node *newNode = (node *)malloc(sizeof(node));
            newNode->idx = end - 1;
            newNode->weight = weight * -1;
            newNode->link = NULL;
            if (graf[start - 1].link == NULL)
            {
                graf[start - 1].link = newNode;
                graf[start - 1].back = newNode;
            }
            else
            {
                graf[start - 1].back->link = newNode;
                graf[start - 1].back = newNode;
            }
        }
        printf("%s\n", Bellman(N) == 1 ? "YES" : "NO");
        memset(graf, 0, sizeof(graf));
        memset(dist, 0, sizeof(dist));
    }
}