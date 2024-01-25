#include <iostream>
#include <vector>
#include <climits>


using namespace std;
int n, m, k, w;
vector<int> pm;
vector<int> pt;
vector<int> hm;
int ans;
vector<int> a;
int max_damage = 0;

void brute(int step){

    if(step == k){
        int damage = 0;
        vector<int> hit(m); // บอกว่า monster i-th โดนยิงไปเท่าไร่
        for(int i =0; i < k; i++) {
            int monster = a[i];
            if(abs(pt[i] - pm[monster]) <= w){
                hit[monster]++;
            }
        }

        // sum hit
        int sum = 0;
        for(int i =0; i < m; i++) {
            sum += max((hm[i] - hit[i]), 0);
        }
        if (sum < ans) {
            ans = sum;
        }
    } else {
        for(int i =0; i < m; i++){
            a[step] = i;
            brute(step+1);
        }

    }
}


int main()
{
    cin >> n >> m >> k >> w;
    pt.resize(k);
    pm.resize(m);
    hm.resize(m);
    a.resize(k);


    for(int i =0; i < m; i++) {cin >> pm[i];}
    for(int i =0; i < m; i++) {cin >> hm[i]; ans+= hm[i];}
    for(int i =0;i < k; i++) {cin >> pt[i];}
    brute(0);
    cout << ans;


}
