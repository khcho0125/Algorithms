#include<stdio.h>
#include<string.h>

#define ll long long
#define LCM(a, b, g) (a / g * b)

typedef struct ExtendedEuclid {
    ll g, x, y;
}EE;

EE xGCD(ll a, ll b) {
    if(b == 0) return (EE){a, 1, 0};
    EE ret = xGCD(b, a % b);
    return (EE){ret.g, ret.y, ret.x - (a / b) * ret.y};
}

char buffer[51];
int letter[50][26];
int length[50];

ll crt() {
    ll a1 = 0, m1 = 1;
    for(int i = 0; buffer[i] != '\0'; i++) {
        ll a2 = letter[i][buffer[i] - 'A'];
        ll m2 = length[i];

        EE mgcd = xGCD(m1, m2);
        if(a2 == -1 || (a2 - a1) % mgcd.g) return -1;
        ll k1 = (a2 - a1) % m2 / mgcd.g * mgcd.x;
        a1 = k1 * m1 + a1;
        m1 = LCM(m1, m2, mgcd.g);

        a1 = (a1 % m1 + m1) % m1;
    }

    return a1;
}

int main() {
    memset(letter, -1, sizeof(letter));

    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%s", buffer);

        int j = 0;
        while(buffer[j] != '\0') {
            letter[i][buffer[j] - 'A'] = j;
            j++;
        }

        length[i] = j;
    }

    scanf("%s", buffer);
    printf("%lld", crt());
}