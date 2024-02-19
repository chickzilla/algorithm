#include <iostream>

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

    for(int i = 1; i <= m ; i++){
        for(int j = 0; j < n; j++){
            dp[i][j] = min(dp[i], dp[i-j])
        }
    }
    return 0;
}
