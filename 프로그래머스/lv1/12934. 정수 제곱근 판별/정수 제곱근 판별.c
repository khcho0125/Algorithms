#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ll long long

ll solution(ll n) {
    for(ll i = 0; i * i <= n; i++) {
        if(i * i == n) return (i + 1) * (i + 1);
    }
    return -1;
}