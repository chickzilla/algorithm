#include <iostream>
#include <vector>

using namespace std;

void recur(vector<vector<int>> &v, int a, int b,int
top,int bottom,int left,int right) {
    if(a == 0){
        v[top][left] = b;
    }
    else if(a > 0){
        int mY = top +bottom >> 1;
        int mX = left + right >> 1;
        // q1 ซ้ายบน
        recur(v,a-1, b, top, mY, left, mX);
        // q2 ขวาบน
        recur(v, a-1, b-1, top, mY, mX, right);
        // q3 .้ายล่าง
        recur(v, a-1, b+1, mY, bottom, left, mX);
        //q4 ขวาล่าง
        recur(v, a-1, b, mY, bottom, mX, right);
    }

}

int main()
{
    int a; int b;
    cin >> a >>b;
    vector<vector<int>> ans(1 << a, vector<int> (1 << a, 0));
    recur(ans, a, b, 0,1 << a, 0, 1 << a );
    for(int i = 0; i < (1<<a); i++){
        for(int j = 0; j < (1<<a); j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
