#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    vector<pair<int, int>> freq;
    int n; int q; int a; int b;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        freq.push_back(make_pair(a, b));
    }
    sort(freq.begin(), freq.end());

    vector<int> all;
    int sum = 0;
    for(int i =0; i <n; i++){
        sum += freq[i].second;
        all.push_back(sum);
    }

    int ans;
    while(q--){
        cin >> ans;
        auto it = lower_bound(all.begin(), all.end(), ans);
        int upper = it-all.begin();
        cout << freq[upper].first << "\n";
    }


    return 0;
}
