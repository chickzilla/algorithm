#include <iostream>
#include <vector>
using namespace std;

void generator(int n, vector<int> &sol, int len, int c, int limit, bool ok){
    if(c == limit) {
            ok = true;
        }
    if(len < n){

        sol[len] = 0;
        generator(n, sol, len+1, 0, limit, ok);


        sol[len] = 1;
        if(c == limit) {
            ok = true;
        }

        generator(n, sol, len+1, c+1, limit, ok);


    } else if(len == n && ok) {
        for(int i =0; i < n; i++){
            cout << sol[i];
        }
        cout << "\n";
    }
}

int main()
{
    int n, limit;
    cin >> n >> limit;
    vector<int> ans(n+5);
    generator(n, ans, 0, 0, limit, false);
    return 0;
}
