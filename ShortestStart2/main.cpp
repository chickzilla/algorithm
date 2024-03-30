#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>


using namespace std;

vector<vector<int>> adjList(5005, vector<int>());
int weight[5005][5005];
int dist[5005];
int n,m,k, goal;

int main()
{
    cin >> n >> m >> k ;
    cin >> goal;
    vector<int> start;
    int s;
    for(int i = 0; i < k; i++){
        cin >> s;
        start.push_back(s);
    }
    int a,b,w;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> w;
        adjList[a].push_back(b);
        weight[a][b] = w;
    }

    int ans = INT_MAX;
    for(auto &first : start){
        for(int i = 0; i < n; i++){dist[i] = 500005;}

        priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > q;

        q.push({0, first});
        dist[first] = 0;



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
        ans = min(ans, dist[goal]);

    }

    cout << ans;




    return 0;
}
