#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Array {
    char set[11];
	int len;
}array;

array arr[1000];

int compare(const void* a, const void* b) {

    array num1 = *(array*)a;
    array num2 = *(array*)b;

	int point = 20;
	char one[21] = {0,};
	char two[21] = {0,};

	for(int i = 0; num1.set[i] != '\0'; i++) {
		one[point - num1.len + i] = num1.set[i];
		two[point - num1.len - num2.len + i] = num1.set[i];
	}

	for(int i = 0; num2.set[i] != '\0'; i++) {
		one[point - num1.len - num2.len + i] = num2.set[i];
		two[point - num2.len + i] = num2.set[i];
	}

	for(int i = 0; i <= 20; i++) {
		if(one[i] < two[i]) {
			return -1;
		}
		if(one[i] > two[i]) {
			return 1;
		}
	}

    return 0;
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%s", arr[i].set);
        arr[i].len = strlen(arr[i].set);
    }
    qsort(arr, N, sizeof(array), compare);
    if(arr[0].set[0] == '0' && arr[0].len == 1) {
        printf("0");
        return 0;
    }
    for(int i = 0; i < N; i++) {
        printf("%s", arr[i].set);
    }
}