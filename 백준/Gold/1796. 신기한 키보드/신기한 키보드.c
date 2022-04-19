#include<stdio.h>
#include<string.h>

#define abs(a) (((a) < 0) ? ((a) * -1) : a)
#define min(a, b) ((a) < (b) ? a : b)
#define max(a, b) ((a) > (b) ? a : b)

typedef struct Map {
	int Min;
	int Max;
	int cnt;
}Map;

Map map[27];
int visit[26] = {0,};

int dp[27][2] = {0,};
int point[27][2] = {0,};

int func(int point, int start, int end, int cnt, int d) {
	int A = abs(point - start);
	int B = abs(start - end);

	return A + B + cnt + d;
}

int main() {
	int len, a, b;
	char str[51];
	scanf("%s", str);

	for(len = 0; str[len] != '\0'; len++) {
		if(!visit[str[len] - 'a']) {
			visit[str[len] - 'a'] = 1;
			map[str[len] - 'a' + 1].Min = len;
			map[str[len] - 'a' + 1].cnt = 0;
		}
		map[str[len] - 'a' + 1].cnt++;
		map[str[len] - 'a' + 1].Max = len;
	}

	for(int i = 1; i <= 26; i++) {
		if(visit[i - 1]) {
			dp[i][0] = min(func(point[i - 1][0], map[i].Min, map[i].Max, map[i].cnt, dp[i - 1][0]), func(point[i - 1][1], map[i].Min, map[i].Max, map[i].cnt, dp[i - 1][1]));
			point[i][0] = map[i].Max; 
			dp[i][1] = min(func(point[i - 1][0], map[i].Max, map[i].Min, map[i].cnt, dp[i - 1][0]), func(point[i - 1][1], map[i].Max, map[i].Min, map[i].cnt, dp[i - 1][1]));
			point[i][1] = map[i].Min;
		}
		else {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1];
			point[i][0] = point[i - 1][0];
			point[i][1] = point[i - 1][1];
		}
	}
	printf("%d", min(dp[26][0], dp[26][1]));
}