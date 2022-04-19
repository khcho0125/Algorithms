#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

typedef struct Shark
{
    int r, c, s, d, z;
} S;

int map[101][101] = {0,};
S shark[10001];
bool Alive[10001];
int update_x[5] = {0, -1, 1, 0, 0};
int update_y[5] = {0, 0, 0, 1, -1};
int R, C;

void update(int idx)
{
    int s = shark[idx].s;
    int &r = shark[idx].r;
    int &c = shark[idx].c;
    int &d = shark[idx].d;
    if (update_x[d])
    {
        if (r + update_x[d] * s > R)
        {
            s -= R - r;
            if (s / (R - 1) % 2)
            {
                r = 1;
                d = 2;
            }
            else
            {
                r = R;
                d = 1;
            }
        }
        else if (r + update_x[d] * s < 1)
        {
            s -= r - 1;
            if (s / (R - 1) % 2)
            {
                r = R;
                d = 1;
            }
            else
            {
                r = 1;
                d = 2;
            }
        }
        r += update_x[d] * (s % (R - 1));
    }
    else
    {
        if (c + update_y[d] * s > C)
        {
            s -= C - c;
            if (s / (C - 1) % 2)
            {
                c = 1;
                d = 3;
            }
            else
            {
                c = C;
                d = 4;
            }
        }
        else if (c + update_y[d] * s < 1)
        {
            s -= c - 1;
            if (s / (C - 1) % 2)
            {
                c = C;
                d = 4;
            }
            else
            {
                c = 1;
                d = 3;
            }
        }
        c += update_y[d] * (s % (C - 1));
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int M, r, c, s, d, z, sum = 0, line = 0;
    cin >> R >> C >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> shark[i].r >> shark[i].c >> shark[i].s >> shark[i].d >> shark[i].z;
        Alive[i] = true;

        if(shark[i].c == 1 && (!line || shark[line].r > shark[i].r)) line = i;

        map[shark[i].r][shark[i].c] = i;
    }
    for (int king = 1; king <= C; king++)
    {
        if (line)
        {
            sum += shark[line].z;
            Alive[line] = false;
            line = 0;
        }

        if(king != C) {
            memset(map, 0, sizeof(map));

            for (int i = 1; i <= M; i++)
            {
                if (Alive[i])
                {
                    update(i);
                    if(!map[shark[i].r][shark[i].c]) {
                        map[shark[i].r][shark[i].c] = i;
                    }
                    else if(shark[map[shark[i].r][shark[i].c]].z > shark[i].z) {
                        Alive[i] = false;
                    }
                    else {
                        Alive[map[shark[i].r][shark[i].c]] = false;
                        map[shark[i].r][shark[i].c] = i;
                    }
                }
            }

            for(int i = 1; i <= R; i++) {
                if(map[i][king + 1]) {
                    line = map[i][king + 1];
                    break;
                }
            }
        }
    }
    cout << sum;
}