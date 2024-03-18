#include <iostream>
#include <vector>

using namespace std;
// �� direct Graph
// �� DFS �ҡ�ش���������������� ���ǵ�駤�� = 0
// ����� adj �� 0 �������ǡ�����ͧ��
int n,m,k;
int beatiful[5001]; // ��᷹ visted ��� ���������ǡ� = 0
int fire[5001];
vector<vector<int>> Graph(5001, vector<int>());

void DFS(int vectice, int &destroy){
    destroy += beatiful[vectice];
    beatiful[vectice] = 0; // ����͹ visited = true
    for(auto &adj : Graph[vectice]){ // ����ҵ���˹�ѧ��� destroyed
        if(beatiful[adj] != 0){
            //cout << " destroy " << adj << "\n";
            DFS(adj, destroy);
        }
    }
}

int main()
{
    int ans = 0;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> beatiful[i];
        ans += beatiful[i];
    }


    for(int i = 0; i < k; i++){ cin >> fire[i]; }

    int a,b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        Graph[a].push_back(b);
    }
    // ����
    for(int i = 0; i < k; i++){
            // ����� destroy �͡��� �ͺ���������������
        int destroy = 0;
        DFS(fire[i], destroy);
        ans -= destroy;
        cout << ans <<" ";
        /*for(int i = 0; i < n; i++){
            cout << beatiful[i] << " ";
        } cout << "\n";*/
    }





    return 0;
}
