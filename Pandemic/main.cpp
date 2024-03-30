#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// ทำ BFS แต่เอาทุกจังหวัดที่มีภูเขาเอามาใส่ queue ก่อน
// mark จังหวัดที่ไมีภูเขาว่าจะไม่ทำ และเอามาบอกด้วยว่าติดเชื้อไหม
// มี  queue อันแรกสำหรับวันที่ x อีกอันวันที่ x+1
using namespace std;
int mark[501][501];
int r,c,t;
queue<vector<int>> q; // เป็น vector เพราะ เป็นพิกัดใส่ 2 ตัว เก็บวันที่ x
queue<vector<int>> q2; // เก็บไว้ใช้สำหรับวันที่ x+1

// บอกว่า q ที่ใส่เข้ามาเป็นตัวไหน
int BFS(queue<vector<int>> &q_use, bool isQ_one){
    int ans = 0;

    while(q_use.size() > 0){
        vector<int> vertice = q_use.front();
        q_use.pop();
        int row = vertice[0];
        int col = vertice[1];



        for(int i = max(0,row-1); i < min(r, row+2); i++){
            for(int j = max(0, col-1); j < min(c, col+2); j++){
                // ไม่มีแนวทแยง
                if(i == row || j == col){
                    if(mark[i][j] == 0){
                        // ใส่ q ที่จะใช้ในวันต่อไป
                        //cout << i << " " << j << " | ";
                        if(isQ_one){
                            q2.push({i, j});
                        } else {
                            q.push({i, j});
                        }
                        // maek ว่าติด ไวรัสแล้ว
                        mark[i][j] = 1;
                        ans++;
                    }
                }
            }
        }
    }
    cout << "\n";

    return ans;
}


int main()
{
    cin >> r >> c >> t;
    int x;
    int ans = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> x;
            if(x != 0){
                mark[i][j] = x;
                if( x == 1){
                    // เอาติดเชื้อมาใส่ queue ก่อน + จำนวนติดเชื้อ
                    q.push({i,j});
                    ans++;
                }
            }
        }
    }

    for(int i = 1; i <= t; i++){
        if(q.empty()){
            ans += BFS(q2, false);
        }else {
            ans += BFS(q, true);
        }
         //cout << "day " << i << " " << ans << "\n";
    }
    cout << ans;


    return 0;
}
