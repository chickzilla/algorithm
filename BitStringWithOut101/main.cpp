#include <iostream>

using namespace std;

// n , 2 ตัวท้าย
long long dp[10005][2][2];


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    long long n;
    long long mod = 100000007;
    cin >> n;


    dp[1][0][0] = dp[1][0][1] = 1;
    dp[2][0][0] = dp[2][0][1] = dp[2][1][0] = dp[2][1][1] = 1;

    for(long long i = 3; i <=n ;i++){
        dp[i][0][0] = (dp[i-1][0][0] + (dp[i-1][1][0] % mod) ) % mod;
        dp[i][0][1] = dp[i-1][0][0];
        dp[i][1][0] = (dp[i-1][1][1] + (dp[i-1][0][1])% mod ) % mod;
        dp[i][1][1] = (dp[i-1][1][1] + (dp[i-1][0][1] % mod) % mod);
    }



    long long ans = 0;
    ans = (((dp[n][0][0] + dp[n][0][1]) % mod) + ((dp[n][1][0] + dp[n][1][1]) % mod)) % mod;
    cout << ans;


    return 0;
}
