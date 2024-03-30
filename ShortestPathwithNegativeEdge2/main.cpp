#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,e,s;
int dist[105];

vector<pair<int,int>> edges;
int weight[105][105];

int main()
{
    cin >> n >> e >> s;
    int a,b,x;
    for(int i = 0; i < e; i++){
        cin >> a >> b >> x;
        edges.push_back({a,b});
        weight[a][b] = x;
    }

    for(int i = 0; i < n; i++){
        dist[i] = 500000;
    }

    dist[s] = 0;
    for(int i = 0; i < n; i++){
        for(auto &e : edges){
            int to = e.first;
            int from = e.second;

            dist[from] = min(dist[from], dist[to] + weight[to][from]);

        }
    }

    bool isCyle = false;
    for(auto &e : edges){
            int to = e.first;
            int from = e.second;

            if(dist[to] + weight[to][from] < dist[from]){
                isCyle = true;
            }
        }

    if(isCyle){
        cout << "-1";
    } else {
        for(int i = 0; i < n; i++){
            cout << dist[i] << " ";
        }
    }
    return 0;
}
