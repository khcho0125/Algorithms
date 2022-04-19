#include<stdio.h>
char data[2188][2188]={};

int main()
{
    int n;
    scanf("%d", &n);
    for(int pro=0; pro < n; pro++)
    {
        for(int pro2=0; pro2 < n; pro2++)
        {
            if(pro%3==1 && pro2%3==1)
            {
                data[pro][pro2] = ' ';
            }
            else if((pro/3)%3==1 && (pro2/3)%3==1)
            {
                data[pro][pro2] = ' ';
            }
            else if((pro/9)%3==1 && (pro2/9)%3==1)
            {
                data[pro][pro2] = ' ';
            }
            else if((pro/27)%3==1 && (pro2/27)%3==1)
            {
                data[pro][pro2] = ' ';
            }
            else if((pro/81)%3==1 && (pro2/81)%3==1)
            {
                data[pro][pro2] = ' ';
            }
            else if((pro/243)%3==1 && (pro2/243)%3==1)
            {
                data[pro][pro2] = ' ';
            }
            else if((pro/729)%3==1 && (pro2/729)%3==1)
            {
                data[pro][pro2] = ' ';
            }
            else if((pro/2187)%3==1 && (pro2/2187)%3==1)
            {
                data[pro][pro2] = ' ';
            }
            else
            {
                data[pro][pro2] = '*';
            }
        }
    }
    for(int pri=0; pri < n; pri++)
    {
        for(int pri2=0; pri2 < n; pri2++)
        {
            printf("%c", data[pri][pri2]);
        }
        printf("\n");
    }
    return 0;
}