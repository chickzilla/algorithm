#include <iostream>

using namespace std;

int main()
{
    int n, b;
    cin >> n;
    int dp[n+2];
    dp[0] = 0;

    for(int i = 2; i <= n+1; i++){
        cin >> b;

        // ���͡��Ҩ���ҵ�ǡ�͹˹�� ���� 2 ��ǡ�͹˹�� ���� ����ѹ�ͧ ( 3 ��ǡ�͹˹�� + ����ѹ�ͧ )
        dp[i] = max(max(dp[i-2],dp[i-1]) ,dp[max(0, i-3)] + b);
    }
    cout << dp[n+1];
    return 0;
}
