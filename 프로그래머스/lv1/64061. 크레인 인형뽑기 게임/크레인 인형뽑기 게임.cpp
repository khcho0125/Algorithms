#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0, back = 0;
    queue<int> map[31];
    int stack[1001] = {0,};

    int row = board[0].size();
    int len = board.size();
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < row; j++) {
            if(board[i][j] != 0) {
                map[j + 1].push(board[i][j]);
            }
        }
    }

    for (int i : moves)
    {
        if(map[i].empty()) continue;
        stack[back] = map[i].front();
        map[i].pop();
        if(back != 0 && stack[back] == stack[back - 1]) {
            answer += 2;
            back -= 2;
        }
        back++;
    }
    return answer;
}