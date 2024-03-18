#include <iostream>
#include <vector>

using namespace std;
// เป็น direct Graph
// ทำ DFS จากจุดที่ไฟไหม้ไปเรื่อยๆ แล้วตั้งค่า = 0
// ถ้าเจอ adj เป็น 0 อยู่แล้วก็ไม่ต้องทำ
int n,m,k;
int beatiful[5001]; // ใช้แทน visted เลย ถ้าเคยไปแล้วก็ = 0
int fire[5001];
vector<vector<int>> Graph(5001, vector<int>());

void DFS(int vectice, int &destroy){
    destroy += beatiful[vectice];
    beatiful[vectice] = 0; // เหมือน visited = true
    for(auto &adj : Graph[vectice]){ // หาว่าตัวไหนยังไม่ destroyed
        if(beatiful[adj] != 0){
            //cout << " destroy " << adj << "\n";
            DFS(adj, destroy);
        }
    }
}

int main()
{
    int ans = 0;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> beatiful[i];
        ans += beatiful[i];
    }


    for(int i = 0; i < k; i++){ cin >> fire[i]; }

    int a,b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        Graph[a].push_back(b);
    }
    // ไหม้
    for(int i = 0; i < k; i++){
            // ใส่ค่า destroy บอกว่า รอบนี้ทำลายไปเท่าไหร่
        int destroy = 0;
        DFS(fire[i], destroy);
        ans -= destroy;
        cout << ans <<" ";
        /*for(int i = 0; i < n; i++){
            cout << beatiful[i] << " ";
        } cout << "\n";*/
    }





    return 0;
}
