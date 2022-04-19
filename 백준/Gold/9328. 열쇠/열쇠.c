#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Space
{
    int x;
    int y;
} space;

typedef struct Door
{
    int x;
    int y;
    struct Door *link;
} Door;

typedef struct list
{
    Door *link;
    Door *back;
} list;

list door[26];
space road[10000];
int pre, temp, key, all, find;
char map[101][101];
int visit[101][101] = {
    0,
};

void open()
{
    Door *query = (Door *)malloc(sizeof(Door));
    for (int i = 0; i < 26; i++)
    {
        if (key & (1 << i))
        {
            query = door[i].link;
            while (query != NULL)
            {
                road[pre].x = query->x;
                road[pre++].y = query->y;
                query = query->link;
            }
            door[i].link = NULL;
        }
    }
}

void door_I(int idx, int x, int y)
{
    Door *D = (Door *)malloc(sizeof(Door));
    D->x = x;
    D->y = y;
    D->link = NULL;
    if (door[idx].link == NULL)
    {
        door[idx].link = D;
        door[idx].back = D;
    }
    else
    {
        door[idx].back->link = D;
        door[idx].back = D;
    }
}

int BFS(int x, int y, int xlim, int ylim)
{
    if (x != 0 && map[x - 1][y] != '*' && !visit[x - 1][y])
    {
        if (map[x - 1][y] >= 'A' && map[x - 1][y] <= 'Z')
        {
            if(key & (1 << (map[x - 1][y] - 'A'))) {
                road[pre].x = x - 1;
                road[pre++].y = y;
            }
            else {
                door_I(map[x - 1][y] - 'A', x - 1, y);
            }
        }
        else
        {
            if (map[x - 1][y] >= 'a' && map[x - 1][y] <= 'z')
            {
                key = key | (1 << (map[x - 1][y] - 'a'));
            }
            else if (map[x - 1][y] == '$')
            {
                find++;
            }
            road[pre].x = x - 1;
            road[pre++].y = y;
        }
        visit[x - 1][y] = 1;
    }
    if (y != 0 && map[x][y - 1] != '*' && !visit[x][y - 1])
    {
        if (map[x][y - 1] >= 'A' && map[x][y - 1] <= 'Z')
        {
            if(key & (1 << (map[x][y - 1] - 'A'))) {
                road[pre].x = x;
                road[pre++].y = y - 1;
            }
            else {
                door_I(map[x][y - 1] - 'A', x, y - 1);
            }
        }
        else
        {
            if (map[x][y - 1] >= 'a' && map[x][y - 1] <= 'z')
            {
                key = key | (1 << (map[x][y - 1] - 'a'));
            }
            else if (map[x][y - 1] == '$')
            {
                find++;
            }
            road[pre].x = x;
            road[pre++].y = y - 1;
        }
        visit[x][y - 1] = 1;
    }
    if (x + 1 != xlim && map[x + 1][y] != '*' && !visit[x + 1][y])
    {
        if (map[x + 1][y] >= 'A' && map[x + 1][y] <= 'Z')
        {
            if(key & (1 << (map[x + 1][y] - 'A'))) {
                road[pre].x = x + 1;
                road[pre++].y = y;
            }
            else {
                door_I(map[x + 1][y] - 'A', x + 1, y);
            }
        }
        else
        {
            if (map[x + 1][y] >= 'a' && map[x + 1][y] <= 'z')
            {
                key = key | (1 << (map[x + 1][y] - 'a'));
            }
            else if (map[x + 1][y] == '$')
            {
                find++;
            }
            road[pre].x = x + 1;
            road[pre++].y = y;
        }
        visit[x + 1][y] = 1;
    }
    if (y + 1 != ylim && map[x][y + 1] != '*' && !visit[x][y + 1])
    {
        if (map[x][y + 1] >= 'A' && map[x][y + 1] <= 'Z')
        {
            if(key & (1 << (map[x][y + 1] - 'A'))) {
                road[pre].x = x;
                road[pre++].y = y + 1;
            }
            else {
                door_I(map[x][y + 1] - 'A', x, y + 1);
            }
        }
        else
        {
            if (map[x][y + 1] >= 'a' && map[x][y + 1] <= 'z')
            {
                key = key | (1 << (map[x][y + 1] - 'a'));
            }
            else if (map[x][y + 1] == '$')
            {
                find++;
            }
            road[pre].x = x;
            road[pre++].y = y + 1;
        }
        visit[x][y + 1] = 1;
    }
}

int main()
{
    int T, h, w;
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
        scanf("%d %d", &h, &w);
        pre = 0, temp = 0, key = 0, all = 0, find = 0;

        for (int i = 0; i < 26; i++)
        {
            door[i].link = NULL;
        }
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                scanf(" %1c", &map[i][j]);
                if ((i == 0 || j == 0 || i == h - 1 || j == w - 1) && map[i][j] != '*')
                {
                    if (map[i][j] >= 'A' && map[i][j] <= 'Z')
                    {
                        door_I(map[i][j] - 'A', i, j);
                    }
                    else
                    {
                        if (map[i][j] >= 'a' && map[i][j] <= 'z')
                        {
                            key = key | (1 << (map[i][j] - 'a'));
                        }
                        else if (map[i][j] == '$')
                        {
                        
                            find++;
                        }
                        road[pre].x = i;
                        road[pre++].y = j;
                    }
                    visit[i][j] = 1;
                }
                if (map[i][j] == '$')
                    all++;
            }
        }
        char input[27];
        scanf("%s", input);
        for (int i = 0; input[i] != '\0' && input[i] != '0'; i++)
        {
            key = key | (1 << (input[i] - 'a'));
        }
        open();
        while (temp != pre && find != all)
        {
            BFS(road[temp].x, road[temp].y, h, w);
            temp++;
            if(temp == pre) open();
        }

        printf("%d\n", find);
        memset(visit, 0, sizeof(visit));
    }
}