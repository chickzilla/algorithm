#include <iostream>
#include <algorithm>

using namespace std;
int food[200001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, K, m;
    cin >> n >> K >> m;
    for(int i = 1; i <= n; i++){
        cin >> food[i];

        // เราจะใช้  lower_bound เพราะไวกว่าไม่ติด T
        food[i] += food[i-1] - m;
    }
    int p,w;

    for(int i = 0; i < K ; i++){
        cin >> p >> w;

        int ans = lower_bound(food+p, food+n+1, w + food[p-1]) - food;

        cout << ans << "\n";
    }

    return 0;
}
