#include <iostream>

using namespace std;

// N, ��Ѻ��, ���/��
int dp[31][31][2];
int main()
{
    int N,M,K;
    cin >> N >> M >> K;
    for(int i = 1; i<= N; i++){
            // ��Ѻ��
        for(int j = 1; j <= i; j++){
            // ��� 1 --> ����Ѻ�� + ��Ѻ��
            dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j-1][0]

            // ��� 0 --> ��Ѻ�� + ����Ѻ�� ����� + 0 ������Թ M
            dp[i][j][0] = dp[i-1][j-1][1] + dp[]
        }
    }



    return 0;
}
