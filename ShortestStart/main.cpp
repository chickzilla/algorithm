// �� wight �Դź �� bell-ford
#include <iostream>
#include <vector>

using namespace std;
vector<pair<int ,int>> edges; // ��ŷء edge
vector<int> first; // ���������
int weight[5005][5005]; // ���˹ѡ���
int dist[5005];
int n,k,m, goal;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k ;
    cin >> goal;

    int x;
    for(int i = 0; i < k; i++){
        cin >> x;
        first.push_back(x);
    }
    int a,b,w;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> w;
        edges.push_back({a,b});
        weight[a][b] = w;
    }

    int ans = INT_MAX;


    // �ͧ������ҡ�ء first
    for(auto &f : first){

        for(int i = 0; i < n; i++){
            dist[i] = 5000;// ��Ѻ weight �ء�ͺ���������¹����á
        }
        dist[f] = 0; // ��駵���á�� 0

        // �� n-1 �ͺ ����ӹǹ���
        for(int i = 0; i < n; i++){
            for(auto &e : edges){
                int to = e.first;
                int from = e.second;

                // ��Ѻ��Ҩҡ��Ƿ���������
                dist[from] = min(dist[from], dist[to] + weight[to][from]);
            }
        }
        // ����ͷӤú�����ͧ��Ҥӵͺ�����ͺ����º�ѹ
        ans = min(ans, dist[goal]);


    }
    cout << ans;

    return 0;
}
