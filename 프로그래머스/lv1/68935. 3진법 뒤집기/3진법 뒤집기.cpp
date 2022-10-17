#include <string>
#include <vector>
#include <math.h>

using namespace std;

int opt = 1;

int change(int n) {
    if (!n) return 0;
    int value = change(n / 3) + n % 3 * opt;
    opt *= 3;
    return value;
}

int solution(int n) {
    return change(n);
}