// bellman เป็น array เดียวที่ detect negative cycle
// สมการ dist[v] = min (dist[v], dist[u] + w(a,b) )
#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int n,e,s;
int weight[101][101];
vector<pair<int, int>> edge; // เก็บ edge ทั้งหมด

int dist[101];

int main()
{
    cin >> n >> e >> s;
    int a,b,w;
    for(int i = 0 ; i < e; i++){
        cin >> a >> b >> w;
        edge.push_back(make_pair(a,b));
        weight[a][b] = w; // wight ที่ a โยงไปหา b
    }

    for(int i = 0; i < n; i++){
        dist[i] = 1002; // ยังไม่ไปถึง ใช้ INT_MAX แล้วบอกบวกกันมากๆค่ามันจะติดลบ เลขเอาค่า max c ที่เขากำหนด
    }

    dist[s] = 0; // ตัวแรกที่เราเริ่ม


    // loop n-1 รอบ ( เพิ่มจาก 0 เส้น ไปจน n-1 เส้น )
    for(int i = 0; i < n; i++){
            // loop ทุก edge แล้วอัพเดทค่าเรื่อยๆ
            for(auto &e : edge ){
                int b = e.second;
                int a = e.first;

                // อัพเดทค่า b ตอนแรกๆ b ยังอาจเป็น INT_MAX อยู่ก็อาจคงค่าเดิมจนกว่าค่าก่อนหน้ามันจะเปลี่ยน
                dist[b] = min(dist[b], dist[a] + weight[a][b]); // ตามสมการ


            }
    }
    // check negative cycle
    // loop all edge อีกรอบ
    bool loop = false;
    for(int i = 0; i < n; i++){
        for(auto &e : edge ){
            int b = e.second;
            int a = e.first;
            if(dist[a] + weight[a][b] < dist[b]){
                loop = true; // เจอ loop negative
            }
        }
    }
    if(loop){
        cout << "-1";
    } else {
        for(int i = 0; i < n; i++){
            cout << dist[i] << " ";
        }
    }




    return 0;
}
