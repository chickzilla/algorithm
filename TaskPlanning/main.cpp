#include <iostream>
#include <vector>
#include <queue>

// ทำ Top - sort


using namespace std;

vector<vector<int>> adjList(1001, vector<int>());
vector<int> degree_in(1001);
int main()
{
    int n, m, x;
    cin >> n;
    queue<int> q;

    for(int i = 0; i < n; i++){
        cin >> m;
        for(int j = 0; j < m; j++){
            cin >> x;
            adjList[x].push_back(i); // directtion จากตัวที่ต้องทำก่อน -> ตัวที่ต้องทำหลัง
            degree_in[i]++;
        }
        if(degree_in[i] == 0){
            q.push(i); // degree_in = 0 แปลว่าทำได้ก่อน
        }
    }
    vector<int> ans;

    while(q.size() > 0){
        int vertice = q.front();
        q.pop();
        ans.push_back(vertice);

        for(auto &adj : adjList[vertice]){
            degree_in[adj]--; // ลบ degree ตัวติดกันไป 1
            if(degree_in[adj] == 0){ // ไม่มี task ก่อนหน้าแล้ว
                q.push(adj);
            }
        }
    }

    for(auto &x : ans){
        cout << x << " ";
    }




    return 0;
}
