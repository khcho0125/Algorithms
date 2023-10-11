#include<stdio.h>
#include<stdbool.h>

#define P_SIZE 10
#define SHAPE 5
#define INF 101

#define min(a, b) ((a) < (b) ? a : b)

int table[P_SIZE + 1][P_SIZE + 1];
int paper[SHAPE];
bool visited[P_SIZE + 1][P_SIZE + 1];
int result = INF;

// 방문을 처리하는 함수
void visit(int xs, int xe, int ys, int ye, bool w) {
    for(int i = xs; i <= xe; i++)
        for(int j = ys; j <= ye; j++)
            visited[i][j] = w;
}

/**
 * 모양을 만들 수 있는지 확인하는 함수
 * 
 * ex) 1*1 에서 2*2로 만들기 위해 1을 검사함
 * 0 -> 01
 *      11
*/
bool canShape(int xs, int xe, int ys, int ye) {
    for(int i = xs; i < xe; i++) if(!table[i][ye] || visited[i][ye]) return false;
    for(int i = ys; i < ye; i++) if(!table[xe][i] || visited[xe][i]) return false;
    return table[xe][ye] && !visited[xe][ye];
}

/**
 * 백트래킹
 * 
 * 전체를 돌며 table[x][y]가 1일 때 색종이 덮기를 시도
*/ 
void tracking(int x, int y, int cnt) {
    // 끝까지 도착했을 경우
    if(x == P_SIZE) {
        result = min(result, cnt);
        return;
    }

    // table[x][y]가 0이거나 이미 덮여있을 때
    if(!table[x][y] || visited[x][y]) {
        tracking(x + (y + 1) / P_SIZE, (y + 1) % P_SIZE, cnt);
        return;
    }

    // 모양별로 덮어보기
    for(int shape = 0; shape < SHAPE; shape++) {
        if(!canShape(x, x + shape, y, y + shape)) break;

        if(!paper[shape]) continue;

        visit(x, x + shape, y, y + shape, true);
        paper[shape]--;
        tracking(x + (y + 1) / P_SIZE, (y + 1) % P_SIZE, cnt + 1);
        visit(x, x + shape, y, y + shape, false);
        paper[shape]++;
    }
}

int main() {
    for(int i = 0; i < P_SIZE; i++) {
        for(int j = 0; j < P_SIZE; j++) {
            scanf("%d", &table[i][j]);
        }
    }

    for(int i = 0; i < SHAPE; i++) paper[i] = 5;

    tracking(0, 0, 0);
    
    // 도착한 기록이 없을 경우 -1 출력
    if(result == INF) result = -1;

    printf("%d", result);
}