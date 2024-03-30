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
    int n;
    cin >> n;
    int s;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> s;
            if(s != 0 && s != -1){
                adjList[i].push_back(j);
                weight[i][j] = s;
            }
        }
        dist[i] = 5000000;
    }

    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
    q.push({0, 1});
    dist[1] = 0;

    while(q.size() > 0){
        int Time = q.top().first;
        int vertice = q.top().second;
        q.pop();

        for(auto &adj : adjList[vertice]){
            if(Time + weight[vertice][adj] < dist[adj]){
                dist[adj] = Time + weight[vertice][adj];
                q.push({dist[adj], adj});
            }
        }
    }

    int ans = INT_MIN;
    for(int i = 1; i<= n; i++){
        ans = max(ans, dist[i]);
    }
    cout << ans;
    return 0;
}
