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
            // check ��Ҷ�ҵ�ǹ���Թ
            if(i - s[j] >= 0){
                    // ex ��� 2 �颹Ҵ 1,1  ��� s[j] = 1 �ѹ������ 1,1,1 ��ͨҡ���
                    // --> ��Ҥ�Ңͧ����������
                dp[i] = (dp[i] + (dp[i-s[j]] % mod)) % mod;
            }
        }
    }

    cout << dp[n];
    return 0;
}
