#include <stdio.h>

int main()
{
    int input, result = 0;
    int arr[101] = {0,};
    for(int i = 0; i < 3; i++) {
        scanf("%d", &input);
        arr[input]++;
    }
    
    for(int i = 0; i < 101; i++) {
        while(arr[i]) {
            arr[i]--;
            if(result) {
                result = i;
                goto play;   
            }
            result = i;
        }
    }
    play : 
    printf("%d", result);
}