#include <iostream>

using namespace std;


int dp[31][31][31];
int n,m,k;

//RELATION
// T(N, M, K) = T(N - 1, M, K - 1) + T(N - 2, M, K - 1) + ... + T(N - M, M, K - 1)

int main()
{
    int n,m,k;
    cin >> n >>m >> k;
    int ans = 0;





    return 0;
}
