// ใช้ dijkstart เพราะเป็น negative จริงแต่ไม่มี cycle negative
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;
int n,m,k, goal;

vector<vector<int>> adjList(5001, vector<int>());
vector<int> first;
int dist[5005];
int weight[5001][5001];


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m >> k;
    cin >> goal;
    int x;
    for(int i = 0; i < k; i++){
        cin >> x;
        first.push_back(x);
    }

    int a,b,w;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> w;
        adjList[a].push_back(b);
        weight[a][b] = w;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q; // pair เก็บ weight and node


    int ans = INT_MAX; // เราจะหา min ที่น้อยสุด
    for(auto &f : first){
        // clear q กับ dist
        for(int i = 0; i < n; i++){
            dist[i] = 5000; // dist ตอนแรกทุกตัวเป็น inf ( 5000 )
        }
        q = priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>(); // clear

        //init ตัว first
        q.push({0, f});
        dist[f] = 0;


        while(q.size() > 0){

            int vertice = q.top().second;
            int T = q.top().first;
            q.pop();


            for(auto &adj : adjList[vertice]){
                    // เจอ Time ที่น้อยกว่า
                if(T + weight[vertice][adj] < dist[adj]){
                    dist[adj] = T + weight[vertice][adj];
                    q.push({dist[adj], adj});
                }
            }
        }

        // เอา ans ที่ goal แต่ละรอบมาหา min
        ans = min(ans, dist[goal]);
    }

    cout << ans;


    return 0;
}
