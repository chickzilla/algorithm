// ใช้ Floyd-warshall ปกติเลย
// ผ่านไป 1 วันเพิ่ม 1 node ก็เหมือนเพิ่ม k
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
int dist[705][705]; // เก็บแค่ dist พอ
int n, w;

int main()
{
    cin >> n >> w;
      // ตั้งให้ทุกค่าเป็น INF ก่อนเพราะยังไม่ถึง
    for(int i = 1; i<= n; i++){
        for(int j = 1; j <= n; j++){
            dist[i][j] = 3000000;
            if(i == j){
                dist[i][j] = 0;
            }
        }
    }

    int freq, a, x;
    // ใส่ weight 3 4 ... n
    for(int i = 3; i <= n ; i++){
        cin >> freq;
        for(int j = 0; j < freq; j++){
            cin >> a >> x;
            dist[i][a] = dist[a][i] = x;
        }
    }


    // ใส่ dist ให้ระหว่าง 1 กับ 2
    dist[1][2] = dist[2][1] = w;

    // ทำ floy ปกติเลย เพราะแต่ละ k มันก็เพิ่ม node k มาคำนวณ
    for(int k = 3; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i != j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        cout << dist[1][2] << " ";
    }
    return 0;
}
