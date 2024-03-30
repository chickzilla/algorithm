// use Dijkstra เพราะเราเอาแค่ตัวติดกันมาคิด
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int R,C, x;
    cin >> R >> C;
    int dist[R][C]; // เก็บระยะทาง
    int fee[R][C]; // ค่าผ่านทาง
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> x;
            fee[i][j] = x;
            dist[i][j] = INT_MAX;// dist เป็น inf เพราะยังไม่ไป
        }
    }

    // ยาวจัด จริงๆทำเป็น vector ดีฟว่า
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> q; // เก็บ dist( Time ) กับพิกัด node
    q.push(make_pair(0, make_pair(0,0))); // dist 0 ให้กับพิกัด ( 0,0 )
    dist[0][0] = 0;

    while(q.size() > 0){
        int Time = q.top().first; // Alarm time
        pair<int, int> vertice = q.top().second; // เอาพิกัด
        int r = vertice.first;
        int c = vertice.second;
        q.pop();


        // node or Grid ที่ติดกัน
        for(int i = max(0, r-1); i < min(R, r+2);  i++){
            for(int j = max(0, c-1); j < min(C, c+2); j++){
                // ไม่เอาแนวทแยง
                if((i == r || j == c)){
                    // ถ้าเจอ path ( free ) ที่น้อยกว่า ก็เอาไปแทนที่ตัวเก่า
                    if(Time + fee[i][j] < dist[i][j]){
                        dist[i][j] = Time + fee[i][j];
                        q.push(make_pair(dist[i][j], make_pair(i,j)));
                    }
                }
            }
        }

    }

// print dist ทั้งหมด
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}
