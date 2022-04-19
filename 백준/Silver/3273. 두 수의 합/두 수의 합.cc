#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100000;
 
int arr[MAX];

 

int main(void)

{

        ios_base::sync_with_stdio(0);

        cin.tie(0);

        int N, X;

        cin >> N;

 

        for (int i = 0; i < N; i++)

                 cin >> arr[i];

        cin >> X;
        sort(arr, arr + N);

        int result = 0;

        for (int i = 0; i < N; i++)

        {

                 int low = 0, high = N - 1;

                 while (low <= high)

                 {

                         int mid = (low + high) / 2;

                         if (arr[mid] == X - arr[i])

                         {

                                 result++;

                                 break;

                         }

                         else if (arr[mid] < X - arr[i])

                                 low = mid + 1;

                         else

                                 high = mid - 1;

                 }

        }
        cout << result / 2 << "\n";

        return 0;

}