// use djikstal algo but keep max Time
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;
vector<vector<int>> adjList(50005, vector<int>());
vector<int> first; // เก็บตัวที่จะติดครั้งแรก
vector<int> weight(50005); // บอกว่าตัวไหนใช้เวลเท่าไหร่ในการติดไวรัส
vector<int> time_alarm(50005);
int n,m,k;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m >> k;
    int x;
    for(int i = 0; i < k; i++){
        cin >> x;
        first.push_back(x);
    }
    for(int i = 0; i < n; i++){
        cin >> weight[i]; // ใส่เวลาป้องกัน
        time_alarm[i] = INT_MAX; // ใส่ค่า max aka inf
    }
    int a,b;
    for(int i = 0; i < m;i++){
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> q; // เก็บเวลา กับ เลข node เรียงน้อย -> มาก

    for(auto &f : first){ // เอาตัวที่ติดครั้งแรกมาใส่ก่อน
        q.push(make_pair(weight[f], f)); //ใส่เวลาที่จะติดไวรัส
        time_alarm[f] = weight[f];
    }


    while(q.size() > 0){
        int Time = q.top().first;
        int vertice = q.top().second;
        q.pop();

        // loop ตัวใกล้เคียงแล้วหาว่าเวลามันน้อยกว่าไหม
        for(auto &adj : adjList[vertice]){
            if(Time + weight[adj] < time_alarm[adj]){
                time_alarm[adj] = Time + weight[adj];

                q.push(make_pair((Time + weight[adj]), adj));
            }
        }
    }
    int last_time = 0; // เก็บเวลาสุดท้ายที่จะติดไวรัส

    for(int i = 0; i < n; i++){
        last_time = max(last_time, time_alarm[i]); // เวลาสุดท้าย = max เวลาที่สุด
    }
    cout << last_time;



    return 0;
}
