#include <string>
#include <vector>

using namespace std;

string week[7] = {
    "SUN",
    "MON",
    "TUE",
    "WED",
    "THU",
    "FRI",
    "SAT"
};
int days[13][32] = {0,};
int year[13] = {
    0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

string solution(int a, int b) {
    int state = 4;
    for(int i = 1; i <= 12; i++)
        for(int j = 1; j <= year[i]; j++)
            days[i][j] = state = (state + 1) % 7;
    return week[days[a][b]];
}