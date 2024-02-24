#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[501][501];
int main()
{
    string a,b;
    cin >> a >> b;
    int len_a = a.size();
    int len_b = b.size();

    for(int i = 1; i <= len_a; i++){
        for(int j = 1; j <= len_b; j++){
                // ลบ 1 เพราะ string เริ่มนับจาก 0
                if(a[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
        }
    }

    cout << dp[len_a][len_b];

    return 0;
}
