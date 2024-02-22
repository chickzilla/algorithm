#include <iostream>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

int dp[1005][1005];
int main()
{
    int r,c;
    cin >> r >> c;
    int max_D = INT_MIN;

    string x;
    for(int i = 1; i <= r; i++){
        cin >> x;
        for(int j = 1; j <= c; j++){
            dp[i][j] = x[j-1] - '0';
            // DP
            // Flow --> First check ��͹��� 1 ��� ������Ѻ��ͨҡ 3 ��ǡ�͹ ������������ 0 ( 仵�������)
            //check ��� ���� ������ �§ �� ����ѹ �Թ����ش �������ѹ���� �ó� 0 0 0 �����ѹ 1
            // ���ҷ�� 3 �����ҡѹ���ǡ 1 --> �ͧ��¹�ٹ�Ҩ����
            // ������Ҷ����¹ min ��� 3 ��� �ǡ 1 �Ф�ͺ�����ء�ó�
            if(dp[i][j] == 0){
                dp[i][j] = 0;
            } else {
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]) , dp[i-1][j-1]) +1;
            }
            max_D = max(max_D, dp[i][j]);
        }
    }
    cout << max_D;
    return 0;
}
