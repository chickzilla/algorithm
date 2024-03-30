#include <iostream>
#include <vector>
#include <queue>


// BFS ปกติเลยแล้วหาว่าตรงไหนห่าง k
using namespace std;

vector<vector<int>> adjList(1001, vector<int>());
vector<int> dist(1001);
int n,e,k;

int BFS(int vertice){
    int ans = 0;
    queue<int> q;
    q.push(vertice);
    dist[vertice] = 0;

    while(q.size() > 0){
        int ver = q.front();
        q.pop();

        for(auto &adj : adjList[ver]){
            if(dist[adj] == -1){
                dist[adj] = dist[ver] + 1;
                q.push(adj);

                // distance == k คือใช่
                if(dist[adj] == k){
                    ans++;
                }
            }
        }

    }
    return ans;

}


int main()
{
    cin >> n >> e >> k;
    int a,b;
    for(int i = 0; i < e ; i++){
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    for(int i = 0; i <= n; i++){dist[i] = -1;}
    cout << BFS(0);
    return 0;
}
