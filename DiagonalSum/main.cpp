#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n][n];
    for(int i =0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    // solve dynamic
    // kadane algo with dynamic
    int max_far = INT_MIN;
    for(int i =0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!(i == 0 || j ==0)){
                arr[i][j] = max(arr[i-1][j-1] + arr[i][j], arr[i][j]);
            }
            //cout << i << " " << j << " " << arr[i][j] << "\n";
            max_far = max(max_far, arr[i][j]);
        }
    }

    cout << max_far ;


    return 0;
}
