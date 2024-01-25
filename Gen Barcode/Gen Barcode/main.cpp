#include <iostream>
#include <vector>

using namespace std;

void generator(int n, vector<int> &sol, int len, int c, int k){
    if(len < n) {
        sol[len] = 0;
        generator(n, sol,len+1, c, k);

        sol[len] = 1;
        generator(n, sol, len+1, c+1, k);
    } else if(len == n && c == k){
        for(int i = 0; i < n; i++){
            cout << sol[i];
        }
        cout << "\n";
    }
}

int main()
{
    int n, k;
    cin >> k >> n;
    vector<int> ans(n+5);
    generator(n, ans, 0, 0, k);

    return 0;
}
