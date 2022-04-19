#include<stdio.h>

int fib(int num){
    if(num > 1){
        return fib(num - 1) + fib(num - 2);
    }
    else return num;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", fib(n));
}