#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
// Use BFS กับทุก node โดยให้ max distance แค่ k
// O(N(N+E))

vector<vector<int>> adjList(1001, vector<int>());
int N,E,K;

int bfs(int vectice){
    // Normal BFS
    vector<int> dist(1001);
    for(int i = 0; i < N; i++){dist[i] = -1;}
    queue<int> q;
    q.push(vectice);
    dist[vectice] = 0;

    int all_friend = 1; // เก็บว่ามีกี่ node รวมตัวมันเองด้วย

    // ข้างหน้า BFS ธรรมดา แต่ข้างหลังเป็นเช็คว่าควรที่จะแตกตัว adj ต่อไหม ( แตกต่อแล้วเกิน K )
    while(q.size() > 0 && dist[q.front()] + 1 <= K){
        int cur_ver = q.front();
        q.pop();
        // adj ของตัวแรกของ queue
        for(auto &adj : adjList[cur_ver]){
            if(dist[adj] == -1){
                dist[adj] = dist[cur_ver] + 1;
                q.push(adj);
                all_friend++; // --> มี friend เพิ่ม
            }
        }
    }
    return all_friend;
}

int main()
{
    cin >> N >> E >> K;
    int a,b;
    for(int e = 0; e <E; e++){
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    int max_friend = INT_MIN;

    // BFS กับทุกๆ node
    for(int i = 0; i < N; i++){
        max_friend = max(max_friend, bfs(i));
    }
    cout << max_friend;

    return 0;
}
