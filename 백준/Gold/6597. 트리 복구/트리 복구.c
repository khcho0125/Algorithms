#include<stdio.h>
#include<string.h>

char PreOrder[27];
char InOrder[27];
int Address[27];

int pre = 0;

void tree(int start, int end) {  
    if(start > end) return;
    int mid = Address[PreOrder[pre++] - 'A'];

    tree(start, mid - 1);
    tree(mid + 1, end);

    printf("%c", InOrder[mid]);
}

int main() {
    int len;
    while(1) {
        scanf("%s %s", PreOrder, InOrder);
        len = strlen(PreOrder);
        if(!len) {
            break;
        }
        
        for(int i = 0; InOrder[i] != '\0'; i++) {
            Address[InOrder[i] - 'A'] = i;
        }

        tree(0, len - 1);

        printf("\n");
        pre = 0;
        memset(PreOrder, 0, sizeof(PreOrder));
    }
}