// ทำ dijlsta แล้วหาว่ามีเมืองที่มีค่า INF ไหม ถ้ามีตอบ -1 ถ้าไม่หา max ของทุกเมือง

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
vector<vector<int>> adjList(1005, vector<int>());
int dist[1005];
int weight[1005][1005];

int main()
{
    int n, x;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> x;
            if(x != -1 && x != 0){
                adjList[i].push_back(j);
                weight[i][j] = x;
            }
        }
        dist[i] = INT_MAX;
    }

    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> q;

    // เมืองหลวงคือเมือง 1
    q.push({0,1});
    dist[1] = 0;
    // ทำแบบปกติเลย
    while(q.size() > 0){
        int vertice = q.top().second;
        int Time = q.top().first;
        q.pop();

        for(auto &adj : adjList[vertice]){
            if(Time + weight[vertice][adj] < dist[adj]){
                dist[adj] = Time + weight[vertice][adj];
                q.push({dist[adj], adj});
            }
        }
    }

    // forloop หาค่า max ถ้ามีตัว 1 ก็ให้ ตอบ -1
    int ans = INT_MIN;
    bool no_path = false;
    for(int i = 1; i <= n; i++){
        if(dist[i] == INT_MAX){
            no_path = true;
            break;
        }
        ans = max(ans, dist[i]);
    }

    if(no_path){
        cout << "-1";
    }else {
        cout << ans;
    }


    return 0;
}
