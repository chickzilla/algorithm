#include <iostream>
#include <algorithm>

using namespace std;

int dp[10001];

// �ԸդԴ --> ���͡��Ҷ����ҵ�ǵ��˹駷�� i �ҤԴ���Ǩ������ѧ����˹���ҧ
// ex 5 1 | 1 99 1 99 1
// dp --> 1 99 2 100 3
// loop ����� ��� ��� i �֧ i -2k + 1
// 2k+1 �����º�����ѹ������ʨ�����ժ�ͧ��ҧ����ͧ
// ex ��� k = 1 ���� i = 5 �ѹ�����͡����Ҩе����ѧ�ҡ 4, 3, 2 ***
int main() {
    int n,k,x;
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin >> x;
        if(i <= k+1){
            // ex �ó� k =1; i = 3 �ѹ������͡�� 2, 1, 0 ���ԧ� 0 �ѹ����������ѹ����� station
            dp[i] = x;
        } else {
            // ����� min ����ش�ͧ i ��Ҷ�����͡ i ���Ǥ�õ�͵���˹
            dp[i] = dp[i-1] + x; // --> �͹�Դ min �ѹ���� != 0 �е�� dp[i] =9999999 ����
            for(int j = 1; j <= (k*2)+1; j++){
                // ��������ҡó� ����ѹ == 0
                if(i-j >= 1){
                    dp[i] = min(dp[i-j]+ x, dp[i]);
                }
            }
        }
    }

    int min_ans = dp[n];
    // max(1,n-k) �����աó� k > n
    for(int i = n; i >= max(1,n-k) ; i--){
        // ����ҵ�ͧ���ʶҹ��˹����ѹ�ѧ�ç condition ���Ǥ�ҹ����ش
        min_ans = min(min_ans, dp[i]);
    }
    cout << min_ans;
}
