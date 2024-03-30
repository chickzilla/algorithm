// �� bellman �� max path �ҡ����� positive cycle

#include <iostream>
#include <climits>

using namespace std;
double fee[505][505];
double dist[505];


int main()
{
    int k,n;
    cin >> k;
    for(int table = 0; table < k; table++){
        cin >> n;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> fee[i][j];
            }
            dist[i] = INT_MIN; // ��Ҩ��� max ����� INT_MIN
        }

        dist[0] = 1; // �ӹǹ��� = 1

        // �� bellman ���� max(dist[i][j], dist[i-1][a] * fee[a][j]) �����ٳ���д�������
        for(int i = 0; i < n; i++){
            // loop �ء edge
            for(int c1 = 0; c1 < n; c1++){
                for(int c2 = 0; c2 < n; c2++){
                    dist[c2] = max(dist[c2], dist[c1] * fee[c1][c2]); // �� max ᷹ min
                }
            }
        }

        // check positive cycle ���ǹ�ա�ͺ���Ǥ������
        // ǹ�ء edge ���Ƿ�����͹���
        int cycle = false;
        for(int c1 = 0; c1 < n; c1++){
            for(int c2 = 0; c2 < n; c2++){
                if(dist[c1] * fee[c1][c2] > dist[c2]){
                    cycle = true;
                }
            }
        }
        if(cycle){
            cout << "YES \n";
        } else {
            cout << "NO \n";
        }

    }

    return 0;
}
