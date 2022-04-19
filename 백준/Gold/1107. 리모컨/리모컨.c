#include<stdio.h>
int broken[11] = {0,};
int num_1,num_2,num, N,goal,min=1000000, length,l;
int check(int);

int main()
{
    scanf("%d %d", &goal, &N);
    num_1 = goal - 100;
    if(num_1 < 0)num_1 = -1 * num_1;

    for(int i = 0; i < N; i++)
    {
        int k;
        scanf("%d", &k);
        broken[k] = 1;
    }

    for(int i = 0; i < 1000001; i++)
    {
        length=check(i);
        if(length)
        {
            int k = goal - i;
            if(k < 0) k = k *- 1;
            if(k < min)
            {
                min = k;
                l = length;
            }
        }
    }
    num_2 = min + l;

    printf("%d", num_1 < num_2 ? num_1 : num_2);

    return 0;
}

int check(int k)
{
    int length = 0;
    if(k == 0)
    {
        return broken[0] ? 0 : 1;
    }
    while (k)
    {
        length++;
        if(broken[k % 10]) return 0;
        k /= 10;
    }
    return length;    
}