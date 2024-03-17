#include <iostream>

using namespace std;

int dp[40001];
int cut[3];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < 3; i++){cin >> cut[i];}

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++){
            if(i - cut[j] >= 0){

                dp[i] = max(dp[i- cut[j]]+ 1, dp[i]);

            }
        }
    }
    cout << dp[n];



    return 0;
}
