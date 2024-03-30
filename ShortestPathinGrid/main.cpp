#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// ใช้ BFS แต่มีการเทียบ distance ว่า เอาตัว min (น้อยสุด)
// มีจุดท้องหมด  <= c*r ตัว ( ไม่นับตัว # )

vector<vector<int>> adjList(1001, vector<int>());
int defect[101][101]; // เก็บว่าจุดไหนเป็น # บ้าง


int main()
{
    int c, r;
    cin >> c >> r;
    char x;
    int dist[r+1][c+1];
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> x;
            if(x == '#'){defect[i][j] = 1;}
            dist[i][j] = -1;
        }
    }

    // สร้าง graph โดยไม่เอาตัว defect
    // ไม่ต้องมีกราฟก็ได้ เพราะยังไงเราก็รู้ว่ามันเอาแค่ตัว รอบทิศ ที่ไม่ใช่ #

    // ทำ Bfs ตั้งแต่จุดรแก
    queue<vector<int>> q; // เก็บ vector เพราะบอก x, y
    q.push({1,1});

    vector<int> vectice;
    vector<vector<int>> adjust;
    while(q.size() > 0){

        vectice = q.front();
        int row = vectice[0];
        int col = vectice[1];
        q.pop();

        // adjust ของ vectice คือ บน ขวา ล่าง ซ้าย
        // แล้วทำ BFS ปกติ
        for(int i = max(1,row -1); i <= min(r, row + 1); i++){
            for(int j = max(1, col-1); j <= min(c, col +1); j++){
                if(i == row || j == col ){ // check ว่าไม่ใช่ตัวทแยง
                    if(defect[i][j] != 1 && dist[i][j] == -1){

                        dist[i][j] = dist[row][col]+1;
                        q.push({i, j});
                    }
                }
            }
        }
    }

    cout << dist[r][c];




    return 0;
}
