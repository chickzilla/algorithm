#include <iostream>

using namespace std;

int dp[10005][2];

int main()
{
    int n, mod = 100000007;
    cin >> n;

    for(int i = 1; i <= n; i++){
        dp[i][0] = (dp[i-1][0] + (dp[i-1][1] % mod)) % mod;
        dp[i][1] = (dp[i-1][1] + (dp[i-1][0] % mod)/2) % mod;
    }
    cout << dp[n][0] + dp[n][1];
    return 0;
}
