#include<stdio.h>
#include<algorithm>

#define max(a, b) (a > b ? a : b)

using namespace std;

typedef struct LINE {
    int first;
    int second;
}LINE;

bool compare(const LINE& a, const LINE& b) {
    if(a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int N, result = 0;
    scanf("%d", &N);
    LINE* lines = (LINE*)malloc(sizeof(LINE) * N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &lines[i].first, &lines[i].second);
    }

    sort(lines, lines + N, compare);

    result += lines[0].second - lines[0].first;
    for(int i = 1; i < N; i++) {
        if(lines[i - 1].first <= lines[i].first && lines[i - 1].second >= lines[i].first && lines[i - 1].second < lines[i].second) {
            result += lines[i].second - lines[i - 1].second;
        }
        else if(lines[i - 1].second < lines[i].first) {
            result += lines[i].second - lines[i].first;
        }
        lines[i].second = max(lines[i].second, lines[i - 1].second);
    }
    
    printf("%d", result);
}