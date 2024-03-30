#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
// Use BFS �Ѻ�ء node ����� max distance �� k
// O(N(N+E))

vector<vector<int>> adjList(1001, vector<int>());
int N,E,K;

int bfs(int vectice){
    // Normal BFS
    vector<int> dist(1001);
    for(int i = 0; i < N; i++){dist[i] = -1;}
    queue<int> q;
    q.push(vectice);
    dist[vectice] = 0;

    int all_friend = 1; // ������ա�� node �������ѹ�ͧ����

    // ��ҧ˹�� BFS ������ ���ҧ��ѧ������Ҥ�÷���ᵡ��� adj ������ ( ᵡ��������Թ K )
    while(q.size() > 0 && dist[q.front()] + 1 <= K){
        int cur_ver = q.front();
        q.pop();
        // adj �ͧ����á�ͧ queue
        for(auto &adj : adjList[cur_ver]){
            if(dist[adj] == -1){
                dist[adj] = dist[cur_ver] + 1;
                q.push(adj);
                all_friend++; // --> �� friend ����
            }
        }
    }
    return all_friend;
}

int main()
{
    cin >> N >> E >> K;
    int a,b;
    for(int e = 0; e <E; e++){
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    int max_friend = INT_MIN;

    // BFS �Ѻ�ء� node
    for(int i = 0; i < N; i++){
        max_friend = max(max_friend, bfs(i));
    }
    cout << max_friend;

    return 0;
}
