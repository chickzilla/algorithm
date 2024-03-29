#include <iostream>

using namespace std;

int main()
{
    int n, mod;
    cin >> n;

    mod = 100000007;
    int dp[10000005][2];

    // ����� 3 Ẻ --> 00 ˹�� ��ѧ , 01 ˹�� ��ѧ , 10 ˹����ѧ --> 01 = [[0, 1]]
    dp[1][0] = 1; //--> [[0], [0]]
    dp[1][1] = 2; //--> [[1,0], [0,1]]

    for(int i = 2; i <= n; i++){
        // ��� [0,0] �ͧ��ѧ ( ����ҡ�����ҷ���������� )
        dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % mod;

        // ����ҡ 1 ������ --> 0+1  �Ѻ 1 0   + �ǡ 0 �����ҷ����� ������� [0, 1] ��� [1, 0]
        //�                          1+0       0 1
        dp[i][1] = (dp[i-1][1] + (2* dp[i-1][0])%mod) % mod;

    }
    cout << (dp[n][1] + dp[n][0])%mod;


    return 0;
}
