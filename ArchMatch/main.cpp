#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// start, stop
int dp[502][502];
int arr[501];
int n;

int dc(int start, int stop){
    if(start < 0 || start > n || stop > n || stop < 0) return 0;


    if(start >= stop){
        dp[start][stop] = 0;
        return 0;
    }
    if(stop - start == 1) {
        dp[start][stop] = arr[start] * arr[stop];
        return dp[start][stop];
    }



    int k = stop - start + 1;
    int max_sides = INT_MIN;
    for(int i = 0 ; i< k; i++){


        int no_stop = 0;
        if(start+i < stop){
            if(dp[start][start+i] == -1){
                dp[start][start+i] = dc(start, start+i);
            }
            no_stop = dp[start][start+i];
        }

        int no_start = 0;
        if(start+i+1 < stop){
            no_start = dp[start+i+1][stop] != -1 ? dp[start+i+1][stop] : dc(start+i+1, stop);

        }

        max_sides = max(max_sides, no_start + no_stop);

    }


    int middle = dp[start+1][stop-1] != -1 ? dp[start+1][stop-1] : dc(start+1, stop-1);

    dp[start][stop] = max(max_sides, max(arr[start]*arr[stop], 0) + middle);


    return dp[start][stop];



}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i <= n ; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = -1;
        }
    }
    cout << dc(1, n) <<"\n";

    return 0;
}
