#include <iostream>
#include <algorithm>
using namespace std;

int n,w,k;
int main()
{
    ios_base::sync_with_stdio(false);  cin.tie(NULL);
    cin >> n >> w >> k;
    int rs[n+1]; int ls[n+1];
    rs[0] = 0; ls[0] = 0;
    for(int i = 1; i<= n; i++) cin >> rs[i];
    for(int i = 1; i<= n; i++) cin >> ls[i];

    for(int i = 1; i <= n; i++){

        int max_r = 0;
        int max_l = 0;

        for(int j = max(0,i-2*w); j < i-w; j++){

            // Logic ข้อนี้ => เลือกว่าจะเติมตัวนี้ต่อจากตัวไหน

            max_r = max(max_r, ls[j]);
            max_l = max(max_l, rs[j]);

        }

        rs[i] = max_r + rs[i];
        ls[i] = max_l + ls[i];

    }
    sort(rs, rs+n+1);
    sort(ls, ls+n+1);

    cout << max(rs[n], ls[n]);






    return 0;
}
