// ใช้ bellman หา max path จากนั้นหา positive cycle

#include <iostream>
#include <climits>

using namespace std;
double fee[505][505];
double dist[505];


int main()
{
    int k,n;
    cin >> k;
    for(int table = 0; table < k; table++){
        cin >> n;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> fee[i][j];
            }
            dist[i] = INT_MIN; // เราจะหา max เลยใช้ INT_MIN
        }

        dist[0] = 1; // จำนวนเท่า = 1

        // ทำ bellman แต่ใช้ max(dist[i][j], dist[i-1][a] * fee[a][j]) เราใช้คูณเพราะดูเป็นเท่าๆ
        for(int i = 0; i < n; i++){
            // loop ทุก edge
            for(int c1 = 0; c1 < n; c1++){
                for(int c2 = 0; c2 < n; c2++){
                    dist[c2] = max(dist[c2], dist[c1] * fee[c1][c2]); // ใช้ max แทน min
                }
            }
        }

        // check positive cycle ถ้าวนอีกรอบแล้วค่าเพิ่ม
        // วนทุก edge แล้วทำเหมือนเดิม
        int cycle = false;
        for(int c1 = 0; c1 < n; c1++){
            for(int c2 = 0; c2 < n; c2++){
                if(dist[c1] * fee[c1][c2] > dist[c2]){
                    cycle = true;
                }
            }
        }
        if(cycle){
            cout << "YES \n";
        } else {
            cout << "NO \n";
        }

    }

    return 0;
}
