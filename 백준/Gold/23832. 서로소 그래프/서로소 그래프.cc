#include<stdio.h>
#include<string.h>
#include<vector>

#define ll long long
#define MAX 50000

using namespace std;

ll table[MAX + 1];
int numbers[MAX + 1] = {0,};
vector<int> prime;

void primechk() {
    for(int i = 2; i * i <= MAX; i++) {
        if(!numbers[i]) {
            prime.push_back(i);
            for(int j = i + i; j <= MAX; j += i) {
                numbers[j] = 1;
            }
        }
    }
}

ll EulerPhi(int N) {
    if(table[N] != -1) return table[N];
    
    int n = N;
    ll ans = N;
    for(auto i : prime) {
        if(N % i == 0) {
            ans -= ans / i;
            do {
                N /= i;
            } while(N % i == 0);
        }
    }
    if(N > 1) {
        ans -= ans / N;
    }
    return table[n] = ans;
}

int main() {
    primechk();
    memset(table, -1, sizeof(table));
    table[1] = 0;
    for(int i = 0; i < prime.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(prime[i] * prime[j] <= MAX) table[prime[i] * prime[j]] = EulerPhi(prime[i]) * EulerPhi(prime[j]);
        }
    }
    int N;
    ll count = 0;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        count += EulerPhi(i);
    }
    printf("%lld", count);
}