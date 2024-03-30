#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
// ทำ BFS ของทั้ง 3 คน และ check แต่ละ node ว่า max สุกคือเท่าไหร่
// จากนั้นเอา max มา check min เทียบกับ node อื่นๆ
// เช็คกรณีที่มีคนไป node นั้นไม่ได้ด้วย

using namespace std;
vector<vector<int>> adjList(250001, vector<int>());
int dist[3][250001]; // เก็บ distance ของต่ละคน
int n;

// ทำ BFS ปกติแล้วเก็บ distance ของแต่ละคนไว้
void BFS(int vertice, int t){
    queue<int> q;
    q.push(vertice);
    dist[t][vertice] = 0;

    while(q.size() > 0){
        int vertice = q.front();
        q.pop();
        for(auto &adj : adjList[vertice]){
            if(dist[t][adj] == -1){
                dist[t][adj] = dist[t][vertice] +1;
                q.push(adj);
            }
        }
    }

}

int main()
{
    cin >> n;
    int x, a;
    int t[3];
    cin >> t[0] >> t[1] >> t[2];
    for(int i = 1; i <= n; i++){
        cin >> x;
        for(int j = 0; j < x; j++){
            cin >> a;
            adjList[i].push_back(a);
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 1; j <= n; j++){
            dist[i][j] = -1;
        }
        BFS(t[i], i);
    }

    // เทียบของทุกสถานีว่า ใครมี max ที่่น้อยสุด
    int max_far = INT_MAX;
    for(int i = 1; i <= n; i++){
        int max_cur = 0;
        for(int j = 0; j < 3; j++){
            if(dist[j][i] == -1){
                // ถ้าสถานีนั้นมีคนที่ไม่สามารถไปได้ --> ตั้ง max เลยจะได้ไม่เป็น max_far ใหม่แน่ๆ
                max_cur = INT_MAX; break;
            } else {
                max_cur = max(dist[j][i], max_cur);
            }
        }
        max_far = min(max_far, max_cur);
    }
    cout << max_far;


    return 0;
}
