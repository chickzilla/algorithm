#include <iostream>

using namespace std;


int dp[31][31][31];
int main()
{
    int n,m,k;
    cin >> n >>m >> k;
    int ans = 0;

    // ��� 1 �ء��� ������Ҩ��� consecutive ���˹�� 1
    for(int i=1;i<=m;i++)dp[1][0][i]=1;
    //cout << "test" << "\n";

    for(int i = 2; i <= n; i++){
            // change color ( flip )
        for(int j = 0; j <= k; j++){
            // consecutive
            for(int p = 1; p <= m; p++){
                // �Դ��ҵ͹��������� n-1 �������Ƿ�� n �ѧ�
                // �Դ�ҡ flip + ��� flip
                dp[i][j][p] = dp[i-1][j-1][1] + dp[i-1][j][p-1];
                if(i == n && j == k){
                    cout << "j " << j << " p " << p << " " << dp[i][j][p] << "\n";
                }
            }
        }
    }

    //cout << ans;



    return 0;
}
