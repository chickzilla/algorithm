#include <iostream>
#include <vector>

using namespace std;

// แนวคิด --> จะไม่เป็นเส้นตรงเมื่อตัวนั้นมี เส้น edge >= 2

int v, e;
int component[200001]; // aka visited
vector<vector<int>> Graph(200001, vector<int>());

// Normal DFS but component บอกว่าอยู่ component ไหน ( cc_num )
// ต้อง check ด้วยว่าไม่ circular ---> ต้องมี 1 ปมที่ connect แค่คนเดียว ( ปลาย )
void DFS(int vectice, int &cc_num, bool &isLine, bool &haveOneEdgeNode){
    component[vectice] = cc_num;

    // ระหว่าง DFS ก็ check ว่าตัวนั้นมี edge เชื่อมมากกว่า 2 ไหม ถ้ามากกว่า = แตกเอาค่าใส่ isLine

    if(Graph[vectice].size() > 2){
        isLine = false;
        //cout << " detect " << vectice << "\n";
    }

    if(Graph[vectice].size() == 1 || Graph[vectice].size() == 0){ // size == 0 กรณีมี node ตัวเดียว
        haveOneEdgeNode = true; // หาว่ามีตัวที่มี edge เดียวไหม ( กัน circular )
        //cout << " detect 1 edge " << vectice << "\n";
    }

    for(auto &adj : Graph[vectice]){
        if(component[adj] == 0){
            DFS(adj, cc_num, isLine, haveOneEdgeNode);
        }
    }
    return;
}

int main()
{
    cin >> v >> e;

    int a,b;
    for(int i = 0; i < e; i++){ // init Graph with adj list
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    int cc_num = 0;
    bool isLine = true;
    bool haveOneEdgeNode = false;
    int ans = 0;

    // เอาค่า isLine มา check ว่าตัวนั้นเป็น Line ไหม
    for(int i = 0; i < v; i++){
        if(component[i] == 0){
            cc_num++;
            DFS(i, cc_num, isLine, haveOneEdgeNode);
            if(isLine && haveOneEdgeNode) ans++;

            haveOneEdgeNode = false;
            isLine = true;

        }
    }
    cout << ans;

    return 0;
}
