#include <stdio.h>
#include <string.h>

int main()
{
    int T, i, pre, n, len, stop = 0;
    char word[20000][51] = {};
    scanf("%d", &T);
    for (i = 0; i < T; i++) {
        scanf("%s", &word[i]);
    }

    for (i = 1; i < T; i++)
    {
        char key[51] = {};
        strcpy(key, word[i]);
        int keyLen = strlen(key);
        pre = i;
        while(0 < pre) {
            len = strlen(word[pre - 1]);
            if(len < keyLen) {
                break;
            }
            else if(len > keyLen) {
                strcpy(word[pre], word[pre - 1]);
                pre--;
            }
            else {
                n = 0;
                while(key[n] != '\0') {
                    if(word[pre - 1][n] > key[n]) {
                        strcpy(word[pre], word[pre - 1]);
                        pre--;
                        break;
                    }
                    if(word[pre - 1][n] < key[n]) {
                        stop = 1;
                        break;
                    }
                    n++;
                }
                if(key[n] == '\0' || stop) {
                    break;
                }
            }
            if(stop) {
                break;
            }
        }
        if(pre < 0) {
            pre = 0;
        }
        strcpy(word[pre], key);
        stop = 0;
    }

    for (i = 0; i < T; i++)
    {
        if (strcmp(word[i], word[i + 1]))
            printf("%s\n", word[i]);
    }
}