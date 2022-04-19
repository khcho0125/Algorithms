#include <stdio.h>

int array[1000001] = {
    0,
};

int main()
{
    long long min, max, n, temp;
    scanf("%lld %lld", &min, &max);
    int result = max - min + 1;
    for (long long i = 2; i * i <= max && result; i++)
    {
        n = (min / (i * i));
        if(min % (i * i) == 0) n--;
        for(temp = (i * i *(n + 1)); temp <= max; temp += i * i) 
        {
            if(!array[temp - min]) {
                array[temp - min] = 1;
                result--;
            }
        }
    }
    printf("%d", result);
}