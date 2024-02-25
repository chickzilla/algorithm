#include <iostream>
#include <vector>

using namespace std;

vector<int> cost,best;

int main() {
    int n,k;
    cin >> n >> k;
    cost.clear();cost.resize(n);
    best.clear();best.resize(n);
    for (int i = 0;i < n;i++) {
      cin >> cost[i];
    }
    for (int i = 0;i <= std::min(n-1,k);i++) {
      best[i] = cost[i];
    }

//    printf("initial\n");
//    for (int i = 0;i < n;i++) {
//      cout << best[i] << " ";
//    }
//    cout << endl;

    int start = k+1;
    int stop = n-1;
    for (int i = start;i<=stop;i++) {
        cout << i << " cost : " << cost[i] << "\n";
      best[i] = cost[i]+best[i-1];
      for (int j = 1;j <= 2*k+1;j++) {
        if (i-j < 0) break;
        if (cost[i] + best[i-j] < best[i]) best[i] = cost[i] + best[i-j];
        cout << i << " " << j << " " << best[i] <<"\n" ;
      }

        cout << " cal " << i << "\n";
        for (int i = 0;i < n;i++) {
            cout << best[i] << " ";
        }
        cout << endl;
        }

    int ans = best[n-1];
    /*for (int i = n-1;i >= std::max(0,n-k-1);i--) {
      if (best[i] < ans) ans = best[i];
    }*/
    cout << ans << endl;
}
