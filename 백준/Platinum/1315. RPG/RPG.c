#include<stdio.h>
#include<stdlib.h>

#define ll long long
#define max(a, b) ((a) > (b) ? a : b)

typedef struct Quest {
    int idx, STR, INT, PNT;
}Quest;

int orderStr(const void* A, const void* B) {
    Quest* a = (Quest*)A;
    Quest* b = (Quest*)B;

    return a->STR > b->STR ? 1 : -1;
}

int orderInt(const void* A, const void* B) {
    Quest* a = (Quest*)A;
    Quest* b = (Quest*)B;

    return a->INT > b->INT ? 1 : -1;
}

Quest AD[50];
Quest AP[50];

int dp[1001][1001];

int solve(int STR, int INT, int ADI, int API, int PNT, ll visited, int sum, int N) {

    if (dp[STR][INT]) {
        return dp[STR][INT];
    }

    while(ADI != N && AD[ADI].STR <= STR) {
        if (!(visited & (1LL << AD[ADI].idx))) {
            PNT += AD[ADI].PNT;
            visited |= (1LL << AD[ADI].idx);
            sum++;
        }
        ADI++;
    }

    while(API != N && AP[API].INT <= INT) {
        if (!(visited & (1LL << AP[API].idx))) {
            PNT += AP[API].PNT;
            visited |= (1LL << AP[API].idx);
            sum++;
        }
        API++;
    }
    
    dp[STR][INT] = sum;
    
    if (API == N || ADI == N) {
        return dp[STR][INT];
    }

    if (AD[ADI].STR <= STR + PNT)
        dp[STR][INT] = solve(AD[ADI].STR, INT, ADI, API, PNT - (AD[ADI].STR - STR), visited, sum, N);

    if (AP[API].INT <= INT + PNT) {
        int result = solve(STR, AP[API].INT, ADI, API, PNT - (AP[API].INT - INT), visited, sum, N);
        dp[STR][INT] = max(dp[STR][INT], result);
    }

    return dp[STR][INT];
}

int main() {
    int N, STR, INT, PNT;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d %d", &STR, &INT, &PNT);
        AP[i].idx = AD[i].idx = i;
        AP[i].STR = AD[i].STR = STR;
        AP[i].INT = AD[i].INT = INT;
        AP[i].PNT = AD[i].PNT = PNT;
    }

    qsort(AD, N, sizeof(Quest), orderStr);
    qsort(AP, N, sizeof(Quest), orderInt);

    printf("%d", solve(1, 1, 0, 0, 0, 0LL, 0, N));
}