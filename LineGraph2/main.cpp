#include <iostream>
#include <vector>

using namespace std;
int n,e, cc;
vector<vector<int>> adjList(100005, vector<int>());
int component[100005];
bool isLine;

void DFS(int vertice, int &start_end_node, bool &isOneNode){
    component[vertice] = cc;
    int degree = adjList[vertice].size();


    // case ปกติต้องมี degree = 2 และตัวปลาย ( degree 1 มี 2 ตัว )
    if(degree > 2 ){
        isLine = false;
    }

    if(degree == 1){
        start_end_node++;
    }

    if(degree == 0){
        isOneNode = true;
    }

    for(auto &adj : adjList[vertice]){
        if(component[adj] == 0){
            DFS(adj, start_end_node, isOneNode);
        }

    }

}

int main()
{
    cin >> n >> e;
    int a,b;
    for(int i = 0; i < e; i++){
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    int ans = 0;
    for(int i = 0 ; i < n; i++){
        int start_end_node = 0;
        bool isOneNode = false;
        isLine = true;


        if(component[i] == 0){
            cc++;

            DFS(i, start_end_node, isOneNode);
            if(start_end_node != 2){
                isLine = false;
            }

            if(isLine || isOneNode){
                ans++;
            }

        }




    }
    cout << ans;



    return 0;
}
