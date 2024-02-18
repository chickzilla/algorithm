#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    int arr[n+1];
    int con[3] = {a, b, c};
    sort(con, con+3);

    for(int i = 0; i <= n; i++){
        arr[i] = 0;
    }

    for(int i = 1; i<= n; i++){
        int max_cur = 0;
        for(int j = 0; j < 3 ; j++){
            if(i - con[j] >= 0){
                max_cur = max(max_cur, arr[i - con[j]] );
            }
        }
        if(max_cur != 0 || i == con[0]) max_cur++;
        arr[i] = max_cur;
    }
    cout << arr[n];

    return 0;
}
