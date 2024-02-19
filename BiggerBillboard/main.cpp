#include <iostream>

using namespace std;

int main()
{
    int n, b;
    cin >> n;
    int dp[n+2];
    dp[0] = 0;

    for(int i = 2; i <= n+1; i++){
        cin >> b;

        // เลือกว่าจะเอาตัวก่อนหน้า หรือ 2 ตัวก่อนหน้า หรือ ตัวมันเอง ( 3 ตัวก่อนหน้า + ตัวมันเอง )
        dp[i] = max(max(dp[i-2],dp[i-1]) ,dp[max(0, i-3)] + b);
    }
    cout << dp[n+1];
    return 0;
}
