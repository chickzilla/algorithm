#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    int w[n+1];
    int p[n+1];
    w[0] = p[0] = 0;
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= n; i++) cin >> w[i];

    int dp[n+1][m+1];

    for(int i = 0; i <=n; i++){
        for(int j= 0; j <= m; j++){
            cin >> dp[i][j];
        }
    }

    // ���ҡ��Ƿ��¢����������樹�֧ 0,0
    // row --> ��� , col --> ���˹ѡ
    int c = m; int r = n;
    vector<int> ans;

    while(r > 0 && c > 0){
        //cout << r << " " << c << "\n";

        // ��º�ҡ row ������ҡ�������� ����ҡ���������������͡��ǹ��
        // �����������͡���Ѻ� ��Ƿ������ǹ����
        if(dp[r][c] > dp[r-1][c]){
            ans.push_back(r);
            // ��Ѻ wieght
            c -= w[r];
            r -= 1;
        } else {
            r -= 1;
        }
    }

    cout << ans.size() << "\n";

    for(int i =0; i < ans.size() ; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
