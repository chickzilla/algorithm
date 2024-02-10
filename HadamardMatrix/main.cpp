#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

// ถ้าเขียน matrix ออกมาจะเห็นว่าในแถวที่ 1 ก็จะคูรแค่ V1 matrix แถวที่ 2 ก็จะคูณแค่ V2
// เราเอา ans มาเก็บแต่ละแถว


void solve(int start, int stop, vector<int> &ans){
    // ex ตอน H1 ก๋ออกตัวมีนเอง
    if(start == stop){
        ans.push_back(v[start]);
        return ;
    } else {
        int m = start + stop >> 1;
        // แบ่ง ซ้ายขวา บน +    ล่าง -
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
