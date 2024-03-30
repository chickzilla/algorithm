#include <iostream>
#include <vector>
#include <queue>
// use Prim เพราะ ถ้า hrushal มันต้องหา edge ทั้งหมด n*2 นาน
// ใช้ Prim แต่หาตัวที่มากสุดแทน
using namespace std;
int n;
int bestCost[2001]; // เก็บ cost ของตัวใกล้เคียงที่ไปได้
int value[2001]; // เก็บค่าที่ใช้ xor ของแต่บะ node
bool visited[2001]; // ถามว่าเคยไป node นี้ไหม



int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> value[i];
        visited[i] = false;
        bestCost[i] = -1; // ปกติตั้งเป็น inf แต่เราจะเอาตัวที่มากสุด เลยตั้งเป็น -
    }
    priority_queue<pair<int, int>> S; // เก็บ weight และ node
    S.push(make_pair(0, 1)); // init node 1

    long long ans = 0;

    while(!S.empty()){
        pair<int, int> aim = S.top(); // ตัว ที่ weight มากสุด
        S.pop();
        int vertice = aim.second;
        int beatiful = aim.first;

        // check ว่าไม่ซ้ำแน่ เพราะ prio_queue มันลบตัวเก่าไม่ได้
        if(visited[vertice] == false){ // check ทุกครั้ง
            visited[vertice] = true;
            ans+= beatiful;
            // adj ทุกตัว (เป็นได้หมด)
            for(int i = 1; i <= n; i++){
                int xor_val = value[i] ^ value[vertice];
                if(visited[i] == false && xor_val > bestCost[i]){ // ถ้า XOR แล้วค่ามากกว่า
                    bestCost[i] = xor_val; // เอาค่า xor แทน best ของอันเดิม
                    S.push(make_pair(xor_val, i)); // เอาค่า best ใส่ลงไป
                }
            }
        }
    }
    cout << ans;

    return 0;
}
