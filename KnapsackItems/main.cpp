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

    // ชี้จากตัวท้ายขึ้นมาเรื่อยๆจนถึง 0,0
    // row --> ชิ้น , col --> น้ำหนัก
    int c = m; int r = n;
    vector<int> ans;

    while(r > 0 && c > 0){
        //cout << r << " " << c << "\n";

        // เทียบจาก row บนว่ามากกว่ามั้ย ถ้ามากกว่าแปลว่าเราเลือกตัวนี้
        // พอรู้ว่าเลือกก็ขยับไป ตัวที่ใส่ตัวนี้ได้
        if(dp[r][c] > dp[r-1][c]){
            ans.push_back(r);
            // ขยับ wieght
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
