#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<int>> &M, long long r, long long c, int n){
    if(n == 1){
        // พวก row, col ที่เป็นเลขคู่ใช้เข้าแถว/ col ท้ายซึ่งคือ M[1]

        return M[(r-1)][(c-1)];
    } else{
        // check ว่าผ่านคำสั่งอะไรไปแล้วบ้าง
        // ทำให้ตัวใหญ่ อยู่ใน scale เล็กลงไปเรื่อยๆ ( ตัวที่เกิน scale ก็จับ - m )
        // พวก trans ก็สลับที่

        long long m = 1LL << (n-1);
        if(r <= m && c <= m){
            // ซ้ายบน ปกติ
            return solve(M, r, c, n-1);
        } else if (r <= m && c > m){
            // ขวาบน Trans
            return solve(M, c-m, r, n-1);
        } else if (r > m && c <= m){
            // ซ้ายล่าง -1
            return (-1 * solve(M, r-m , c, n-1));
        } else if ( r > m && c > m){
            // ขวาล่าง -1 * tran
            return (-1 * solve(M, c-m, r-m, n-1));
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; int m;
    cin >> n >> m;
    vector<vector<int>>  M(2, vector<int>(2, 0));
    for(int i = 0; i < 2; i++){
        for( int j = 0; j < 2; j++){
            cin >> M[i][j];
        }
    }
    long long r; long long c;
    for(int i = 0; i < m; i++){
        cin >> r >> c;
        cout << solve(M, r, c, n) << "\n";
    }



    return 0;
}
