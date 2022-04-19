#include<stdio.h>

char str[1000000];

int main() {
	int cnt = 0;
	while(scanf("%s", str) != EOF) {
		cnt++;
	}
	printf("%d", cnt);
}