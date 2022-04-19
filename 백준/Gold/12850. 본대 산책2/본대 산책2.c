#include <stdio.h>
#include <string.h>

#define MOD 1000000007LL
#define ll long long

/*  정보과학관 : 0
    전산관 : 1
    미래관 : 2
    신양관 : 3
    한경직기념관 : 4
    진리관 : 5
    형남공학관 : 6
    학생 회관 : 7
*/

ll array[8][8] = {
    {0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 1, 1, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 1, 1, 0}};
ll temp[8][8] = {
    0,
};

void logN(ll (*A1)[8], ll (*A2)[8])
{
    ll tmp;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tmp = 0;
            for (int k = 0; k < 8; k++)
            {
                tmp += A1[i][k] * A2[k][j];
                tmp %= MOD;
            }
            temp[i][j] = tmp;
        }
    }
    for(int i = 0; i < 8; i++) {
        memcpy(A1[i], temp[i], sizeof(A1[i]));
    }
}

int main()
{
    int D;
    scanf("%d", &D);
    ll ans[8][8] = {
        0,
    };
    for (int i = 0; i < 8; i++)
    {
        ans[i][i] = 1;
    }

    while (D)
    {
        if (D & 1)
        {
            logN(ans, array);
            D--;
        }
        logN(array, array);
        D = D >> 1;
    }

    printf("%lld", ans[0][0]);
}