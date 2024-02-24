#include <iostream>

using namespace std;

// N, กลับสี, ขาว/ดำ
int dp[31][31][2];
int main()
{
    int N,M,K;
    cin >> N >> M >> K;
    for(int i = 1; i<= N; i++){
            // กลับสี
        for(int j = 1; j <= i; j++){
            // เติม 1 --> ไม่กลับสี + กลับสี
            dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j-1][0]

            // เติม 0 --> กลับสี + ไม่กลับสี แต่ว่า + 0 ได้ไม่เกิน M
            dp[i][j][0] = dp[i-1][j-1][1] + dp[]
        }
    }



    return 0;
}
