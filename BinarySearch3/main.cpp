#include <iostream>
#include <vector>

using namespace std;

int bs(int start, int stop, vector<int> &v, int q, int idx) {
    if(start < stop) {
        int m = (start + stop) >> 1;
        if(v[m] <= q){
            bs(m+1, stop, v, q, m);
        } else {
            bs(start, m, v, q, idx);
        }
    } else if(start == stop){
        return (v[start] <= q && start > idx) ? start : idx;

    }


}

int main()
{
    int n,q;
    cin >> n >> q;

    vector<int> v(n);
    for(int i =0; i < n; i++) {cin >> v[i];}
    int quest;
    for(int i = 0; i < q; i++) {
        cin >> quest;
        cout << bs(0, n-1, v, quest, -1) << "\n";
    }
    return 0;
}
