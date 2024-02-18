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
    // �ѧ䧡������ 1 ���
    arr[1][0] = 1;
    arr[1][1] = 1;

    for(int i = 2; i <= n; i++){
        // 0 ������ʹ ��йѺ��ʹ
        // ��Ңͧ�ѹ������Ƿ����� 0 + �ѹ������Ƿ����� 1 ��������ѹ�ͧ
        arr[i][0] = (arr[i-1][0] + arr[i-1][1]) % mod;

        // ������ 1 ����ҵ�ͧ�����ͨҡ 0 ��Ƿ�� i - k + 1
        arr[i][1] = arr[max(1,i-k+1)][0] % mod;
    }
    cout << (arr[n][0] + arr[n][1]) % mod;

    return 0;
}
