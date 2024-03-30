#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// �� BFS ���ա����º distance ��� ��ҵ�� min (�����ش)
// �ըش��ͧ���  <= c*r ��� ( ���Ѻ��� # )

vector<vector<int>> adjList(1001, vector<int>());
int defect[101][101]; // ����Ҩش�˹�� # ��ҧ


int main()
{
    int c, r;
    cin >> c >> r;
    char x;
    int dist[r+1][c+1];
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> x;
            if(x == '#'){defect[i][j] = 1;}
            dist[i][j] = -1;
        }
    }

    // ���ҧ graph �������ҵ�� defect
    // ����ͧ�ա�ҿ���� �����ѧ���ҡ��������ѹ������� �ͺ��� �������� #

    // �� Bfs �����ش��
    queue<vector<int>> q; // �� vector ���к͡ x, y
    q.push({1,1});

    vector<int> vectice;
    vector<vector<int>> adjust;
    while(q.size() > 0){

        vectice = q.front();
        int row = vectice[0];
        int col = vectice[1];
        q.pop();

        // adjust �ͧ vectice ��� �� ��� ��ҧ ����
        // ���Ƿ� BFS ����
        for(int i = max(1,row -1); i <= min(r, row + 1); i++){
            for(int j = max(1, col-1); j <= min(c, col +1); j++){
                if(i == row || j == col ){ // check ���������Ƿ�§
                    if(defect[i][j] != 1 && dist[i][j] == -1){

                        dist[i][j] = dist[row][col]+1;
                        q.push({i, j});
                    }
                }
            }
        }
    }

    cout << dist[r][c];




    return 0;
}
