#include<stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    if(n > m) {
        int temp = n;
        n = m;
        m = temp;
    }
    int M_length = (m % 4) == 0 ? 4 : (m % 4);
    int N_length = (n % 4) == 0 ? 4 : (n % 4);
    printf("%d", ((m / 4 + (m % 4 != 0)) - (n / 4 + (n % 4 != 0))) + (M_length > N_length ? M_length - N_length : N_length - M_length));
}