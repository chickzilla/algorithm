#include <iostream>
#include <vector>
#include <algorithm>

int dp[1001][1001];
using namespace std;
int main()
{
    int n,x;
    cin >> n;
    vector<int> v(n);
    vector<int> v_sort(n);

    for(int i = 0 ; i < n ; i++){
        cin >> x;
        v[i] = v_sort[i] = x;
    }
    sort(v_sort.begin(), v_sort.end());

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(v[j-1] == v_sort[i-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[n][n];



    return 0;
}
