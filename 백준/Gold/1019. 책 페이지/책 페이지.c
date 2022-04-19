#include <stdio.h>

#define ll long long

ll set[10] = {
    0,
};

int main()
{
    ll N, front, middle, back = 1;
    scanf("%lld", &N);
    front = N;
    for (ll i = 1; i <= N; i *= 10)
    {
        middle = front % 10;
        front = front / 10;
        if(i == 1)
        {
            for (int j = 0; j < 10; j++)
            {
                set[j] += front * i;
            }
            for (int j = 1; j <= middle; j++)
            {
                set[j] += i;
            }
        }
        else if(front == 0) {
            for (int j = 1; j < middle; j++)
            {
                set[j] += i;
            }
            set[middle] += back;
        }
        else {
            for(int j = 1; j < 10; j++) {
                set[j] += front * i;
            }
            set[0] += (front - 1) * i;
            for(int j = 0; j < middle; j++) {
                set[j] += i;
            }
            set[middle] += back;
        }
        back += middle * i;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%lld ", set[i]);
    }
}