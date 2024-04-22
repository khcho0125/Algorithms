#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        int x, y, z;
        double result;
        cin >> x >> y >> z;

        result = fabs((x + z) / 2. - y);

        printf("#%d %.1f\n", tc, result);
    }
}