#include <iostream>
#include <vector>

using namespace std;

void generator(int n , vector<int> &sol, vector<bool> &check, int len, vector<int> &before) {
    if( len < n) {
        for(int i = 0; i <n ; i++) {
            if(check[i] == false && (before[i] == -1 || check[before[i]])) {
                check[i] = true;
                sol[len] = i;
                generator(n, sol, check, len+1, before);
                check[i] = false;
            }
        }
    } else if (len == n ) {
        for(int i = 0; i < n ;i++){
            cout << sol[i];
        }
        cout << "\n";
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int a,b;
    cin >> n >> m;
    vector<int> ans(n+5);
    vector<bool> check(n+5, false);
    vector<int> before(n+5, -1);



    for(int i = 0; i < m ;i++){
        cin >> a >> b;
        before[b] = a;
    }
    generator(n, ans, check, 0, before);

    return 0;
}
