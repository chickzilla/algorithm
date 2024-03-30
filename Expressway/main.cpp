// �� Floyd-warshall �������
// ��ҹ� 1 �ѹ���� 1 node ������͹���� k
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
int dist[705][705]; // ���� dist ��
int n, w;

int main()
{
    cin >> n >> w;
      // ������ء����� INF ��͹�����ѧ���֧
    for(int i = 1; i<= n; i++){
        for(int j = 1; j <= n; j++){
            dist[i][j] = 3000000;
            if(i == j){
                dist[i][j] = 0;
            }
        }
    }

    int freq, a, x;
    // ��� weight 3 4 ... n
    for(int i = 3; i <= n ; i++){
        cin >> freq;
        for(int j = 0; j < freq; j++){
            cin >> a >> x;
            dist[i][a] = dist[a][i] = x;
        }
    }


    // ��� dist ��������ҧ 1 �Ѻ 2
    dist[1][2] = dist[2][1] = w;

    // �� floy ������� �������� k �ѹ������ node k �Ҥӹǳ
    for(int k = 3; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i != j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        cout << dist[1][2] << " ";
    }
    return 0;
}
