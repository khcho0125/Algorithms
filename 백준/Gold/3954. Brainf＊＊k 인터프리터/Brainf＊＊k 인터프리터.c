#include<stdio.h>
#include<string.h>

int arr[100001]; // 메모리 영역
int pointer;

int stack[2050]; // 괄호 스택
int count[2050]; // 명령 횟수 스택
int pre;

int visit[4100]; // 괄호 방문
int loops[4100]; // 매칭 괄호

char buffer[4100]; // 프로그램 명령
char input[4100]; // 입력
int P, temp;

void solve() {
    memset(arr, 0, sizeof(arr));
    memset(loops, -1, sizeof(loops));
    memset(visit, 0, sizeof(visit));
    memset(count, 0, sizeof(count));
    pointer = pre = P = temp = 0;

    int M, C, I;
    scanf("%d %d %d", &M, &C, &I);
    scanf("%s%s", buffer, input);

    for(int i = 0; i < C; i++) { // 짝을 이루는 괄호 매칭
        if(buffer[i] == ']') {
            loops[i] = stack[--pre];
            loops[loops[i]] = i;
        }
        else if(buffer[i] == '[') {
            stack[pre++] = i;
        }
    }

    while(P < C) { // 명령에서 빠져 나갈 때까지
        switch (buffer[P]) {
        case '+':
            arr[pointer] = (arr[pointer] + 1) % 256;
            break;
        
        case '-':
            arr[pointer] = (arr[pointer] + 255) % 256;
            break;

        case '>':
            pointer = (pointer + 1) % M;
            break;

        case '<':
            pointer = (pointer + (M - 1)) % M;
            break;

        case '[':
            if(!arr[pointer]) {
                P = loops[P];
                break;
            }

            stack[pre++] = P;
            count[pre] = 0;
            break;

        case ']':
            if(arr[pointer]) {
                P = loops[P];
                break;
            }

            pre--;
            count[pre] += count[pre + 1];

            break;

        case ',':
            if(input[temp] == '\0') {
                arr[pointer] = 255;
                break;
            }
            arr[pointer] = input[temp++];
            break;

        default:
            break;
        }
        
        if(pre && ++count[pre] >= 50000000) { // 매 명령마다 괄호 안에 있다면 횟수 증가
            printf("Loops %d %d\n", stack[pre - 1], loops[stack[pre - 1]]);
            return;
        }

        P++;
    }

    printf("Terminates\n");

}

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        solve();
    }
}