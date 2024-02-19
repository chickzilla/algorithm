#include <iostream>

using namespace std;

int main()
{
    int n, b;
    cin >> n;
    int dp[n+1];
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        cin >> b;
        // เลือกระหว่าง เาออันซ้าย หรือเอาตรงนี้แล้ว + อีก 2 ช่องก่อนหน้า
        dp[i] = max(dp[i-1], dp[max(i-2, 0)] + b);
    }
    cout << dp[n];
    return 0;
}
