#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int solve(int arr[], int n, int w){
    int start=0; int stop = 0; int s = 0;

    int max_most = INT_MIN;
    int max_cur = 0;


    for(int i = 0; i < n; i++){
        max_cur = max_cur += arr[i];
        if(max_most < max_cur){
            max_most = max_cur;
            start = s;
            stop = i;
        }

        if(max_cur < 0){
            max_cur = 0;
            s = i+1;
        }
    }



    cout << arr[start] << "\n" << arr[stop] << "\n" << stop - start + 1 << "\n";





    return max_most;




}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n ; int w;
    cin >> n >> w;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << solve(arr, n, w);
    return 0;
}
