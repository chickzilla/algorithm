#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int n, x;
    cin >> n;
    int max_far = INT_MIN;
    int arr[n+1][n+1]; // ชั้นก่อน กับ ชั้นปัจจุบัน
    for(int i = 0; i <= n ; i++){
        for(int j = 0; j <= n; j++){
            arr[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++){
            //cout << i << " ------------- " << "\n";
        for(int j = 1; j <= i; j++){

            cin >> x;
            //cout << x << "-" << "\n";
            // case ปกจิ
            arr[i][j] = max(arr[i-1][j] + x, arr[i-1][j-1] + x);
            max_far = max(max_far, arr[i][j]);
            //cout << arr[i][j] << " ";
        }
        //cout << "\n";
    }

    cout << max_far;
    return 0;
}
