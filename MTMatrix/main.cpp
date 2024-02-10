#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<int>> &M, long long r, long long c, int n){
    if(n == 1){
        // �ǡ row, col ������Ţ����������/ col ���«�觤�� M[1]

        return M[(r-1)][(c-1)];
    } else{
        // check ��Ҽ�ҹ�������������Ǻ�ҧ
        // ��������˭� ����� scale ���ŧ�������� ( ��Ƿ���Թ scale ��Ѻ - m )
        // �ǡ trans ����Ѻ���

        long long m = 1LL << (n-1);
        if(r <= m && c <= m){
            // ���º� ����
            return solve(M, r, c, n-1);
        } else if (r <= m && c > m){
            // ��Һ� Trans
            return solve(M, c-m, r, n-1);
        } else if (r > m && c <= m){
            // ������ҧ -1
            return (-1 * solve(M, r-m , c, n-1));
        } else if ( r > m && c > m){
            // �����ҧ -1 * tran
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
