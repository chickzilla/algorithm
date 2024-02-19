#include <iostream>

using namespace std;

int main()
{
    int n, k, mode = 1000003;
    cin >> n >> k;
    int s[k];
    for(int i = 0; i < k; i++){
        cin >> s[i];
    }

    int dp[n+1];
    dp[0] = 1;

    for(int i = 1; i <= n; i++){
        dp[i] = 0;
        for(int j = 0; j < k; j++){
            // check ว่าถ้าตัวนั้นเกิน
            dp[i] += dp[max(0, i - s[k])];
        }
    }

    cout << dp[n];
    return 0;
}
