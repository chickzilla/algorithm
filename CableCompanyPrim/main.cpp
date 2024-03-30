#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <climits>

//Prim
using namespace std;
vector<vector<int>> adjList(1001, vector<int>());
int weight[1001][1001]; // �� weight edge u/v;
int cost[1001]; // cost ���������ͨ���� node ������
int n;
bool taken[1001];


int main()
{
    cin >> n;
    int x;
    for(int i = 0; i < n; i++){
        cost[i] = INT_MAX; // ��� cost �͹�á����������
        taken[i] = false;
        for(int k = 0; k < n-i-1 ; k++){
            cin >> x;
            int adj = k+i+1;
            adjList[i].push_back(adj);
            adjList[adj].push_back(i);
            weight[i][adj] = weight[adj][i] = x; // weight
        }
    }

    set<pair<int, int>> s; // set ������������ cost �ͧ���� node
    s.insert(make_pair(0, 0)); // ���������ҡ node �á ����� cost �� 0
    while(!s.empty()){

    }


    return 0;
}
