#include <iostream>

using namespace std;

int main()
{
    int n,m,k;
    cin >> n >> m >>k;
    int arr[n][m];
    for(int i = 0; i < n; i++){
        for( int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    int p[n][m];
    p[0][0] = arr[0][0];
    for(int j =0= 1; j < m ; i++){
        p[0][j] = p[0][j-1] + a[0][j];
    }
    for(int i = 1 ; i < n; i++){
        p[i][0] = p[i-1] + p[i][0];
        for(int j = 1; j < m; j++){
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + a[i][j];
        }
    }
    return 0;
}
