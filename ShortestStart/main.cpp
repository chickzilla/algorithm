// มี wight ติดลบ ใช้ bell-ford
#include <iostream>
#include <vector>

using namespace std;
vector<pair<int ,int>> edges; // เก็ลทุก edge
vector<int> first; // ปกเริ่มต้น
int weight[5005][5005]; // น้ำหนักเส้น
int dist[5005];
int n,k,m, goal;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k ;
    cin >> goal;

    int x;
    for(int i = 0; i < k; i++){
        cin >> x;
        first.push_back(x);
    }
    int a,b,w;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> w;
        edges.push_back({a,b});
        weight[a][b] = w;
    }

    int ans = INT_MAX;


    // ลองเริ่มจากทุก first
    for(auto &f : first){

        for(int i = 0; i < n; i++){
            dist[i] = 5000;// ปรับ weight ทุกรอบเมื่อเปลี่ยนตัวแรก
        }
        dist[f] = 0; // ตั้งตัวแรกเป็น 0

        // ทำ n-1 รอบ ตามจำนวนเส้น
        for(int i = 0; i < n; i++){
            for(auto &e : edges){
                int to = e.first;
                int from = e.second;

                // ปรับค่าจากตัวที่เชื่อมมา
                dist[from] = min(dist[from], dist[to] + weight[to][from]);
            }
        }
        // เมื่อทำครบแล้วลองเอาคำตอบแต่ละรอบมาเทียบกัน
        ans = min(ans, dist[goal]);


    }
    cout << ans;

    return 0;
}
