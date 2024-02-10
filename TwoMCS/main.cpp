#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int solve(int arr[], int n){
    int max_st = INT_MIN;
    int max_nd = INT_MIN;
    int start = 0; int stop = 0; int s =0;

    int max_cur = 0;

    for(int i = 0; i < n; i++){
        max_cur += arr[i];
        if(max_cur >= max_st){
            max_st = max_cur;
            start = s;
            stop = i;
        }

        if(max_cur < 0){
            max_cur = 0;
            s = i+1;
        }
    }

    for(int i = start; i <= stop; i++){
        arr[i] = 0;
    }

    max_nd = 0; max_cur = 0; start = 0; stop = 0; s = 0;
    for(int i = 0; i < n; i++){
        max_cur += arr[i];
        if(max_cur >= max_nd){
            max_nd = max_cur;
            start = s;
            stop = i;
        }

        if(max_cur < 0){
            max_cur = 0;
            s = i+1;
        }
    }

    //cout << max_st << "\n" << max_nd << "\n";
     return max_st + max_nd;

}

int main()
{
    int n ;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n; i++){
        cin >> arr[i];
    }
    cout << solve(arr, n);
    return 0;
}

