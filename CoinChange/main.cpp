#include <iostream>
#include <algorithm>

using namespace std;

int dp[10005];

int main()
{
    int n,m;
    cin >> n >> m;
    int coin[n];
    for(int i = 0; i < n; i++){
        cin >> coin[i];
    }

    for(int i = 1;i <= m; i++){
        dp[i] = 999999;
        for(int j = 0; j <n; j++){
            if(i - coin[j] >= 0){
                dp[i] = min(dp[i], 1 + dp[i-coin[j]]);
            }
            /*if(i == 3 ){
                cout << coin[j] << " " << dp[i] << " " << dp[i-j] <<"\n";
            }*/
        }
    }


    /*for(int i = 0; i <=m; i++){
        cout << dp[i] << " ";
    }*/
    cout << dp[m];
    return 0;
}
