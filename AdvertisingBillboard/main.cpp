#include <iostream>

using namespace std;

int main()
{
    int n, b;
    cin >> n;
    int dp[n+1];
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        cin >> b;
        // ���͡�����ҧ ����ѹ���� ������ҵç������� + �ա 2 ��ͧ��͹˹��
        dp[i] = max(dp[i-1], dp[max(i-2, 0)] + b);
    }
    cout << dp[n];
    return 0;
}
