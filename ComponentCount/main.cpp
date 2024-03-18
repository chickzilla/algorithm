#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> Graph(10002, vector<int>());
vector<int> component(10002);

void DFS(int vectice, int cc_num){
    component[vectice] = cc_num;

    for(auto &adj :Graph[vectice]){
        if(component[adj] == 0){
            DFS(adj, cc_num);
        }
    }
}


int main()
{
    int cc_num = 0;
    int v,e, a, b;
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    for(int i = 1; i <= v; i++){
        if(component[i] == 0){
            cc_num++;
            DFS(i, cc_num);
        }
    }
    cout << cc_num;
    return 0;
}
