#include <iostream>
#include <vector>

using namespace std;

// �ǤԴ --> ���������鹵ç����͵�ǹ���� ��� edge >= 2

int v, e;
int component[200001]; // aka visited
vector<vector<int>> Graph(200001, vector<int>());

// Normal DFS but component �͡������� component �˹ ( cc_num )
// ��ͧ check ���������� circular ---> ��ͧ�� 1 ����� connect �褹���� ( ���� )
void DFS(int vectice, int &cc_num, bool &isLine, bool &haveOneEdgeNode){
    component[vectice] = cc_num;

    // �����ҧ DFS �� check ��ҵ�ǹ���� edge ������ҡ���� 2 ��� ����ҡ���� = ᵡ��Ҥ����� isLine

    if(Graph[vectice].size() > 2){
        isLine = false;
        //cout << " detect " << vectice << "\n";
    }

    if(Graph[vectice].size() == 1 || Graph[vectice].size() == 0){ // size == 0 �ó��� node �������
        haveOneEdgeNode = true; // ������յ�Ƿ���� edge ������� ( �ѹ circular )
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

    // ��Ҥ�� isLine �� check ��ҵ�ǹ���� Line ���
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
