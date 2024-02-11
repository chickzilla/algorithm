#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
bool process(int start, int en, vector<int> virus){
        if(en-start == 2) return true;
        int mid = (start+en)/2;
        int rh = 0;
        int lh = 0;

        for(int i = start ; i < mid; i++) rh += virus[i];
        for(int i = mid;i < en; i++) lh += virus[i];
        if( abs(rh-lh) <= 1) return process(start, mid, virus) && process(mid, en, virus);

        return false;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k,m,a;
    bool check;
    cin >> k >> m;
    int l = 1 << m;
    vector<int> virus(l);
    while(k--){
        check = false;
        for(int i = 0; i < l; i++){
            cin >> virus[i];
        }
        cout << (process(0, l, virus)==true ? "yes" : "no");
        cout << "\n";

    }

    return 0;
}
