#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


// ทำ BFS ไปเรื่อยๆจนกว่าจะะเจอขอบ
// ถ้าผ่านตัวที่เป็นหลุมให้เอา ans++ และ ปรับค่าหลุมเป็น 0
using namespace std;

int dist[1001][1001]; // -2 --> หลุดยังไม่กลบ | -1 --> ไม่ใช่หลุม+ยังไม่เดิน | 0 --> จุดแรก หรือ เดินผ่านมาทั้งหมดไม่เคยมีหลุม | x --> เดินมากลบหลุมไปแล้ว x ครั้ง
int N, a, b;


int BFS(){
    int dig = INT_MAX;
    queue<vector<int>> q;
    q.push({a,b}); // จุดเริ่มต้น  บ้าน
    dist[a][b] = 0;

    while(q.size() > 0){
        vector<int> vertice = q.front();
        q.pop();
        int row = vertice[0];
        int col = vertice[1];

        for(int i = max(1, row-1); i <= min(1000, row+1); i++){ // 1000 * 1000
            for(int j = max(1, col-1); j <= min(1000, col+1); j++){

                if(i == row || j == col){ // ไม่มีแนวทแยง
                    if(dist[i][j] == -1 || dist[i][j] == -2){
                        //cout << i << " " << j << "\n";

                        if(dist[i][j] == -2){ // หลุม
                            dist[i][j] = dist[row][col] +1 ; // ถ้าตรงนั้นเป็นหลุม --> กลบเพิ่มเป็น 1
                        } else {
                            dist[i][j] = dist[row][col]; // ถ้าไม่ใช่หลุม ก็ไม่กลบ --> เท่เดิม
                        }
                        if(i == 1000 || j == 1000){
                            dig = min(dig, dist[i][j]);
                            //cout << dig << "\n";
                        } // ถ้าถึงขอบแล้ว
                        q.push({i, j});

                    }

                }
            }
        }


    }
    return dig;

}


int main()
{
    cin >> N >> a >> b;
    int x,y;
    for(int i = 1; i <= 1000; i++){
        for(int j = 1; j <= 1000 ; j++){
            dist[i][j] = -1;
        }
    }

    for(int i = 0 ; i < N ; i++){
        cin >> x >> y;
        dist[x][y] = -2; // หลุม
    }

    cout << BFS();

    return 0;
}
