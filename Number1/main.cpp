#include <iostream>

using namespace std;


int l; int r;

int solve(int start, int stop, int n){

    if(n == 0) return 0;
    if(start > stop || start > r || stop < l) return 0;
    else {
        int m = (start + stop) /2;
        int now = n % 2;

        if(m >= l && m <= r){

        // ��Ѻ�����ǹ ˹��/��ѧ ** �������ç��ҧ

            return now + solve(start, m-1, n/2) + solve(m+1, stop, n/2);
        } else {
            return solve(start, m-1, n/2) + solve(m+1, stop, n/2);
        }


    }



}

int main()
{
    int n;
    cin >> n >> l >> r;


    int len = 0;
    int j = n;
    int i = 1;
    while(j > 1){
        i = 1 + i*2;
        j /= 2;
    }

    // �� length ��� i �������繵�� stop
    cout << solve(1, i, n);
    return 0;
}
