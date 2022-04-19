#include<stdio.h>

int main() {
    int arr[4];
    int Rising = 1;
    int Diving = 1;
    int identical = 1;
    scanf("%d", &arr[0]);
    for(int i = 1; i < 4; i++) {
        scanf("%d", &arr[i]);
        if(arr[i] < arr[i - 1]) {
            Rising = 0;
            identical = 0;
        }
        if(arr[i] > arr[i - 1]) {
            Diving = 0;
            identical = 0;
        }
        if(arr[i] == arr[i - 1]) {
            Rising = 0;
            Diving = 0;
        }
    }
    if(Rising) {
        printf("Fish Rising");
    } else if(Diving) {
        printf("Fish Diving");
    } else if(identical) {
        printf("Fish At Constant Depth");
    } else {
        printf("No Fish");
    }
}