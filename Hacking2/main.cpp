#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n,m,k;
int self_time[60005];
int dist[60005];
vector<vector<int>> adjList(60005, vector<int>());

int main()
{
    cin >> n >> m >> k;
    vector<int> first;
    int x;
    for(int i = 0; i < k; i++){
        cin >> x;
        first.push_back(x);
    }
    for(int i = 0; i < n; i++){
        cin >> self_time[i];
        dist[i] = 50000;
    }
    int a,b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;

    for(auto &f : first){
        q.push({self_time[f],f});
        dist[f] = self_time[f];
    }

    while(q.size() > 0){
        int vertice = q.top().second;
        int Time = q.top().first;
        q.pop();

        for(auto &adj : adjList[vertice]){
            if(Time + self_time[adj] < dist[adj]){
                dist[adj] = Time + self_time[adj];
                q.push({dist[adj], adj});
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, dist[i]);
    }
    cout << ans;


    return 0;
}
