#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <climits>

//Prim
using namespace std;
vector<vector<int>> adjList(1001, vector<int>());
int weight[1001][1001]; // เก็บ weight edge u/v;
int cost[1001]; // cost ที่ใช้เมื่อจะเอา node มาร่วม
int n;
bool taken[1001];


int main()
{
    cin >> n;
    int x;
    for(int i = 0; i < n; i++){
        cost[i] = INT_MAX; // ตั้ง cost ตอนแรกให้เยอะมาๆ
        taken[i] = false;
        for(int k = 0; k < n-i-1 ; k++){
            cin >> x;
            int adj = k+i+1;
            adjList[i].push_back(adj);
            adjList[adj].push_back(i);
            weight[i][adj] = weight[adj][i] = x; // weight
        }
    }

    set<pair<int, int>> s; // set ที่เอาไว้ใส่ cost ของแต่ละ node
    s.insert(make_pair(0, 0)); // ให้เริ่มจาก node แรก และมี cost เป็น 0
    while(!s.empty()){

    }


    return 0;
}
