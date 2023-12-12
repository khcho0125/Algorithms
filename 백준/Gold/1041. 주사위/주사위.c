#include<stdio.h>
#include<stdlib.h>

#define ll long long
#define swap(a, b) {int sw_temp = a; a = b; b = sw_temp;}

typedef struct Dice {
    int first, second, third;
}Dice;

int compare(const void *a, const void *b) {
    Dice *A = (Dice*)a;
    Dice *B = (Dice*)b;

    int Asum = A->first + A->second + A->third;
    int Bsum = B->first + B->second + B->third;

    if(Asum < Bsum) return -1;
    return Asum > Bsum;
}

void sortDice(Dice *dice) {
    if(dice->first < dice->second) swap(dice->first, dice->second);
    if(dice->first < dice->third) swap(dice->first, dice->third);
    if(dice->second < dice->third) swap(dice->second, dice->third);
}

ll minDice(ll size, ll first, ll second, ll third) {
    ll result = first * 4 + second * 8 + third * 8;
    result += (size - 2) * 12 * third + (size - 2) * 8 * second;
    result += (size - 2) * (size - 2) * 5 * third;
    return result;
}

ll solution(int N, int A, int B, int C, int D, int E, int F) {
    if(N == 1) {
        Dice one = (Dice){A, B, C}, two = (Dice){D, E, F};
        sortDice(&one);
        sortDice(&two);
        return A + B + C + D + E + F - (one.first > two.first ? one.first : two.first);
    }

    Dice side[8];

    side[0] = (Dice){A, B, C};
    side[1] = (Dice){A, C, E};
    side[2] = (Dice){A, E, D};
    side[3] = (Dice){A, D, B};
    side[4] = (Dice){F, B, C};
    side[5] = (Dice){F, C, E};
    side[6] = (Dice){F, E, D};
    side[7] = (Dice){F, D, B};

    qsort(side, 8, sizeof(Dice), compare);

    sortDice(&side[0]);
    return minDice(N, side[0].first, side[0].second, side[0].third);
}

int main() {
    int N, A, B, C, D, E, F;
    scanf("%d %d %d %d %d %d %d", &N, &A, &B, &C, &D, &E, &F);
    printf("%lld", solution(N, A, B, C, D, E, F));
}