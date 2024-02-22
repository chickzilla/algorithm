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
            // Flow --> First check ก่อนว่า 1 ไหม ถ้าใช่ก็นับต่อจาก 3 ตัวก่อน ถ้าไม่ก็ให้เป็น 0 ( ไปต่อไม่ได้)
            //check ตัว ซ้าย บนซ้าย แทยง โดย เอาอัน มินที่สุด รวมตัวมันด้วย กรณี 0 0 0 แต่ตัวมัน 1
            // แต่ถ้าทั้ง 3 ตัวเท่ากันให้บวก 1 --> ลองเขียนดูน่าจะรู้
            // จะได้ว่าถ้าเขียน min ทั้ง 3 ตัว บวก 1 จะครอบคลุมทุกกรณี
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
