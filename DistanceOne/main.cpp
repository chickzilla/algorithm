#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, mod;
    // add 0 and add 1 to last
    int arr[5050][2];
    cin >> n >> k;
    mod = 100000007;

    //assign first
    // ยังไงก็มีแน่ๆ 1 ตัว
    arr[1][0] = 1;
    arr[1][1] = 1;

    for(int i = 2; i <= n; i++){
        // 0 ใส่ได้ตลอด และนับตลอด
        // เอาของอันที่แล้วที่เติม 0 + อันที่แล้วที่เติม 1 ก็จะได้ตัวมันเอง
        arr[i][0] = (arr[i-1][0] + arr[i-1][1]) % mod;

        // ถ้าเติม 1 ได้เราต้องเติมต่อจาก 0 ตัวที่ i - k + 1
        arr[i][1] = arr[max(1,i-k+1)][0] % mod;
    }
    cout << (arr[n][0] + arr[n][1]) % mod;

    return 0;
}
