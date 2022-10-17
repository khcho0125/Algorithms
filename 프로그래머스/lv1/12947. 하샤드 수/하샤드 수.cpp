#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int sum = 0, temp = x;
    while(x) {
        sum += x % 10;
        x /= 10;
    }
    return !(temp % sum);
}