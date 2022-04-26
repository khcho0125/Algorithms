#include <string>
#include <iostream>
#include <vector>

using namespace std;

int graf[4][12] = {
    {0, 4, 3, 4, 3, 2, 3, 2, 1, 2, 1}, // 0
    {3, 1, 0, 1, 2, 1, 2, 3, 2, 3, 4}, // 2
    {2, 2, 1, 2, 1, 0, 1, 2, 1, 2, 3}, // 5
    {1, 3, 2, 3, 2, 1, 2, 1, 0, 1, 2} // 8
};

string solution(vector<int> numbers, string hand)
{
    string answer = "";
    string mid = hand == "left" ? "L" : "R";
    int left = 10, right = 10, temp = 0;
    int* useHand = hand == "left" ? &left : &right;
    for (int i : numbers)
    {
        switch (i)
        {
        case 1:
        case 4:
        case 7:
            answer.append("L");
            left = i;
            break;
        case 3:
        case 6:
        case 9:
            answer.append("R");
            right = i;
            break;
        default:
            switch(i) {
                case 0:
                    temp = 0;
                    break;
                case 2:
                    temp = 1;
                    break;
                case 5:
                    temp = 2;
                    break;
                case 8:
                    temp = 3;
                    break;
            }
            if(graf[temp][left] < graf[temp][right]) {
                left = i;
                answer.append("L");
            }
            else if(graf[temp][left] > graf[temp][right]) {
                right = i;
                answer.append("R");
            }
            else {
                *useHand = i;   
                answer.append(mid);
            }
            break;
        }
    }
    return answer;
}