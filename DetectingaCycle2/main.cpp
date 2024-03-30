#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> adjList(1001 ,vector<int>());
bool visited[1001];
int from[1001];

void DFS(int vertice, bool &cycle, int parent){
    visited[vertice] = true;
    for(auto &adj : adjList[vertice]){
        if(visited[adj] == false){
            from[adj] = vertice;
            DFS(adj, cycle, vertice);
        }else {
            // ถ้าตัวที่ชี้กลับไปไม่ใช่ตัวแม่เรา แต่มัน true แปลว่า เดินวน
            if(adj != parent){
                cycle = true;
                return;
            }
        }
    }
}

int main()
{
    int T, n, e, a, b;
    cin >> T;
    for(int t = 0; t < T ; t++){


        cin >> n >> e;
        for(int i = 0; i < e; i++){
            cin >> a >> b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }

        for(int i = 0; i <n; i++){
            visited[i] = false;
            from[i] = -1;
        }

        bool isCycle = false;

        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                DFS(i, isCycle, -1);
            }
            adjList[i] = vector<int>();
        }

        if(isCycle){
            cout << "YES\n";
        }else {
            cout <<"NO\n";
        }
    }
    return 0;
}
