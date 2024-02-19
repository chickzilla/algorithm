#include <iostream>

using namespace std;

int dp[501][501];
int main()
{
    int n,k, mod = 1997;
    cin >> n >> k;




    for(int i = 1; i <= n; i++){
        dp[i][1] = 1;
        for(int j = 2; j <= k; j++){
            dp[i][j] = ((j * dp[i-1][j]) % mod + dp[i-1][j-1]) % mod;
        }
    }


    cout << dp[n][k];
    return 0;
}
