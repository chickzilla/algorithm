#include <iostream>

using namespace std;

int length[10000];
char solve(int n, int k){
    // check �������㹪�ǧ�˹
    if(k == 0){
        return n % 3 == 1 ? 'g' : 'a';
    } else {
        if(n <= length[k-1]){
            return solve(n, k-1);
        }
        n -= length[k-1];

        if(n > k+3) {
            return solve(n - (k+3), k-1);
        } else {
            return n == 1 ? 'g' : 'a';
        }

    }
}

int main()
{
    // �Դ������Ǣͧ����� ga ����� g(k) ���� dc ���Ҥ�õ���ǧ�˹
    int n;
    cin >> n;
    char ans;
    for(int i = 0 ; i <n ; i++){
        // ����Ҥ������ ga ����� k ��ش��Ƿ�� >= n
        // ������Ҥ�� k(aka i) ���令Դ
        length[i] = (i == 0 ? 3 : (length[i-1] * 2) + (i + 3));
        //cout << length[i] << "\n";
        if(length[i] >= n){
            ans = solve(n, i);
            break;
        }
    }
    cout << ans;


    return 0;
}
