#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,w,k;
    cin >> n >> w >> k;
    int l[n+1];
    int r[n+1];
    l[0] = r[0] = 0;

    for(int i = 1; i <= n; i++){
        cin >> l[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> r[i];
    }

    int left= 0;
    for(int i = 1; i <= n; i++){
        // ซ้าย
        int max_pre_left = 0;
        for(int j = 1; j <= w; j++){
            max_pre_left = max(max_pre_left, r[max(i-j, 0)]);
        }
        l[i] = max(max_pre_left, r[max(i-w-1, 0)] + l[i]);

        // ขวา
        int max_pre_rigth = 0;
        for(int j = 1; j <= w; j++){
            max_pre_rigth = max(max_pre_rigth, l[max(i-j, 0)]);
        }
        r[i] = max(max_pre_rigth, l[max(i-w-1, 0)] + r[i]);
    }
    for(int i = 0; i <= n; i++){
        cout << l[i] << " ";
    }
    cout << "\n";

      for(int i = 0; i <= n; i++){
        cout << r[i] << " ";
    }
    cout << "\n";
    return 0;
}
