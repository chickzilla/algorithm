#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,m,x;
    cin >> n >> m;

    int arr[n+1][m+1];

    for(int i = 0; i <=n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0){
                arr[i][j] = 0;
            } else {
                cin >> x;
                if(i == 1 && j == 1) {
                        // case start
                    arr[i][j] = x;
                } else {
                    if(i == 1){
                        // ·∂«∫π ÿ¥‰¡Ë¡’·π« ∑·¬ß
                        arr[i][j] = max(arr[i-1][j]+x, arr[i][j-1]+x);
                    } else {
                        // case ª°®‘
                        arr[i][j] = max(max(arr[i-1][j]+x, arr[i][j-1]+x), arr[i-1][j-1] + (2*x));
                    }
                }
            }
        }
    }


    cout << arr[n][m];


    return 0;
}
