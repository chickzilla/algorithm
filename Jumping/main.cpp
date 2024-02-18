#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);


    int n, x;
    cin >> n;

    // ให้ 3 ช่่องแรกเป็น 0 ในกรณีตัวที่ 1, 2, 3
    int arr[n+3];
    for(int i = 0; i < n+3; i++){
        arr[i] = 0;
    }

    for(int i = 3; i < n+3; i++) {
        cin >> x;

        arr[i] = max(max(arr[i-1] + x, arr[i-2] + x), arr[i-3] + x);
        //cout << arr[i] << " ";

    }
    cout <<  arr[n+2];
    return 0;
}
