#include <iostream>
#include <string>

using namespace std;

int dp[1001][1001];
int main()
{
    int n,m;
    string a,b;
    cin >> n >> m >> a >> b;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            cin >> dp[i][j];
        }
    }

    string ans = "";
    while(n > 0 && m > 0){
        if(dp[n][m] - dp[n-1][m-1] == 1){
            //cout << n << " " << m << "\n";
            ans = a[n-1] + ans;
            n--; m--;
        } else {
            if(dp[n-1][m] >= dp[n][m]){
                n--;
            } else{
                m--;
            }
        }
    }
    cout << ans;

    return 0;
}
