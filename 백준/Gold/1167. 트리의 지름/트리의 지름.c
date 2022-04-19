#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int idx;
    int weight;
    struct Node *link;
} node;

typedef struct Tree
{
    node *link;
    node *back;
} tree;

int visit[100001] = {
    0,
};
tree list[100001];
int length = 0;
int end_point = 0;

void dfs(int x, int point)
{
    visit[x] = 1;
    if (length < point)
    {
        length = point;
        end_point = x;
    }
    node *temp = (node *)malloc(sizeof(node));
    temp = list[x].link;
    while (temp != NULL)
    {
        if(!visit[temp->idx])
            dfs(temp->idx, point + temp->weight);
        temp = temp->link;
    }
}

int main()
{
    int V, parent, children, weight;
    scanf("%d", &V);
    for (int i = 0; i < V; i++)
    {
        scanf("%d %d", &parent, &children);
        list[parent].link = NULL;
        list[parent].back = NULL;
        while (children != -1)
        {
            scanf("%d", &weight);
            node *N = (node *)malloc(sizeof(node));
            N->idx = children;
            N->weight = weight;
            N->link = NULL;
            if (list[parent].link == NULL)
            {
                list[parent].link = N;
                list[parent].back = N;
            }
            else
            {
                list[parent].back->link = N;
                list[parent].back = N;
            }
            scanf("%d", &children);
        }
    }
    dfs(1, 0);
    memset(visit, 0, sizeof(visit));
    length = 0;
    dfs(end_point, 0);
    printf("%d", length);
}