#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
// �� BFS �ͧ��� 3 �� ��� check ���� node ��� max �ء����������
// �ҡ������ max �� check min ��º�Ѻ node ����
// �礡óշ���դ�� node �����������

using namespace std;
vector<vector<int>> adjList(250001, vector<int>());
int dist[3][250001]; // �� distance �ͧ���Ф�
int n;

// �� BFS ���������� distance �ͧ���Ф����
void BFS(int vertice, int t){
    queue<int> q;
    q.push(vertice);
    dist[t][vertice] = 0;

    while(q.size() > 0){
        int vertice = q.front();
        q.pop();
        for(auto &adj : adjList[vertice]){
            if(dist[t][adj] == -1){
                dist[t][adj] = dist[t][vertice] +1;
                q.push(adj);
            }
        }
    }

}

int main()
{
    cin >> n;
    int x, a;
    int t[3];
    cin >> t[0] >> t[1] >> t[2];
    for(int i = 1; i <= n; i++){
        cin >> x;
        for(int j = 0; j < x; j++){
            cin >> a;
            adjList[i].push_back(a);
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 1; j <= n; j++){
            dist[i][j] = -1;
        }
        BFS(t[i], i);
    }

    // ��º�ͧ�ءʶҹ���� ���� max ��������ش
    int max_far = INT_MAX;
    for(int i = 1; i <= n; i++){
        int max_cur = 0;
        for(int j = 0; j < 3; j++){
            if(dist[j][i] == -1){
                // ���ʶҹչ���դ�����������ö��� --> ��� max ��¨�������� max_far �������
                max_cur = INT_MAX; break;
            } else {
                max_cur = max(dist[j][i], max_cur);
            }
        }
        max_far = min(max_far, max_cur);
    }
    cout << max_far;


    return 0;
}
