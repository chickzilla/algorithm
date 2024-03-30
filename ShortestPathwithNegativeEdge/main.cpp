// bellman �� array ���Ƿ�� detect negative cycle
// ����� dist[v] = min (dist[v], dist[u] + w(a,b) )
#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int n,e,s;
int weight[101][101];
vector<pair<int, int>> edge; // �� edge ������

int dist[101];

int main()
{
    cin >> n >> e >> s;
    int a,b,w;
    for(int i = 0 ; i < e; i++){
        cin >> a >> b >> w;
        edge.push_back(make_pair(a,b));
        weight[a][b] = w; // wight ��� a �§��� b
    }

    for(int i = 0; i < n; i++){
        dist[i] = 1002; // �ѧ���件֧ �� INT_MAX ���Ǻ͡�ǡ�ѹ�ҡ����ѹ�еԴź �Ţ��Ҥ�� max c ����ҡ�˹�
    }

    dist[s] = 0; // ����á�����������


    // loop n-1 �ͺ ( �����ҡ 0 ��� 仨� n-1 ��� )
    for(int i = 0; i < n; i++){
            // loop �ء edge �����Ѿഷ����������
            for(auto &e : edge ){
                int b = e.second;
                int a = e.first;

                // �Ѿഷ��� b �͹�á� b �ѧ�Ҩ�� INT_MAX ������Ҩ�������������Ҥ�ҡ�͹˹���ѹ������¹
                dist[b] = min(dist[b], dist[a] + weight[a][b]); // ��������


            }
    }
    // check negative cycle
    // loop all edge �ա�ͺ
    bool loop = false;
    for(int i = 0; i < n; i++){
        for(auto &e : edge ){
            int b = e.second;
            int a = e.first;
            if(dist[a] + weight[a][b] < dist[b]){
                loop = true; // �� loop negative
            }
        }
    }
    if(loop){
        cout << "-1";
    } else {
        for(int i = 0; i < n; i++){
            cout << dist[i] << " ";
        }
    }




    return 0;
}
