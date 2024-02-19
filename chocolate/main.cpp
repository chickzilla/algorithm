#include <iostream>

using namespace std;

int main()
{
    int n, k, mod = 1000003;
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
            if(i - s[j] >= 0){
                    // ex ยาว 2 ได้ขนาด 1,1  ถ้า s[j] = 1 มันก็จะเติม 1,1,1 ต่อจากเดิม
                    // --> เอาค่าของตัวเก่ามาใช้
                dp[i] = (dp[i] + (dp[i-s[j]] % mod)) % mod;
            }
        }
    }

    cout << dp[n];
    return 0;
}
