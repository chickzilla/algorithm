#include <iostream>
#include <vector>
#include <algorithm>

// check circular ปกติ แต่เก็บ distance ด้วย
using namespace std;

int n;
vector<vector<int>> Graph(100001, vector<int>());
vector<bool> visited(100001);
vector<int> from(100001);
vector<int> dist(10001); // เอาไว้เก็บว่าเคลื่อนที่ไปเท่าไหร่
int ans = 0;
bool check = false;



// DFS แต่ใส่ dist บอกด้วยว่าขยับมาเท่าไหร่
void DFS(int vectice){
    if(check) return;
    visited[vectice] = true;

    for(auto &adj : Graph[vectice]){
        if(visited[adj] == false){
            from[adj] = vectice;
            dist[adj] = dist[vectice] + 1;
            DFS(adj);
        } else { // check Circular
            if(from[vectice] != adj){ // วนไปตัวเดิมโดยไม่ใช่ทางเดิม == Circular
                //cout << "CIR " << adj << " " << vectice << "\n";
                ans = max(dist[vectice], dist[adj]) - min(dist[vectice], dist[adj]) + 1;
                check = true;
                break;
            }
        }
    }
    return ;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    int a,b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
        visited[i] = false;
        dist[i] = 0;
    }

    DFS(0);
    //cout << ans;

    /*for(int i = 0; i < n; i++){
       cout << from[i] << " ";
    }
    cout << "\n";

    for(int i = 0; i < n; i++){
       cout << dist[i] << " ";
    }
    cout << "\n";*/


    cout << ans;


    return 0;
}
