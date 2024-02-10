#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

// �����¹ matrix �͡�Ҩ���������Ƿ�� 1 ��Ф���� V1 matrix �Ƿ�� 2 ��Фٳ�� V2
// ������ ans ����������


void solve(int start, int stop, vector<int> &ans){
    // ex �͹ H1 ���͡����չ�ͧ
    if(start == stop){
        ans.push_back(v[start]);
        return ;
    } else {
        int m = start + stop >> 1;
        // �� ���¢�� �� +    ��ҧ -
        vector<int> left_ans;
        vector<int> right_ans;

        solve(start, m, left_ans);
        solve(m+1, stop, right_ans);

        int n = left_ans.size();
        for(int i = 0;  i < n; i++){
            ans.push_back(left_ans[i] + right_ans[i]);
        }
        for(int i = 0; i < n; i++){
            ans.push_back(left_ans[i] - right_ans[i]);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<int> ans(n);
    solve(0, n, ans);
    for(int i = 0; i < n; i++){
        cout << n << " ";
    }
    return 0;
}
