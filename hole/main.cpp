#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


// �� BFS �������樹���Ҩ���͢ͺ
// ��Ҽ�ҹ��Ƿ�������������� ans++ ��� ��Ѻ��������� 0
using namespace std;

int dist[1001][1001]; // -2 --> ��ش�ѧ���ź | -1 --> ���������+�ѧ����Թ | 0 --> �ش�á ���� �Թ��ҹ�ҷ���������������� | x --> �Թ�ҡź��������� x ����
int N, a, b;


int BFS(){
    int dig = INT_MAX;
    queue<vector<int>> q;
    q.push({a,b}); // �ش�������  ��ҹ
    dist[a][b] = 0;

    while(q.size() > 0){
        vector<int> vertice = q.front();
        q.pop();
        int row = vertice[0];
        int col = vertice[1];

        for(int i = max(1, row-1); i <= min(1000, row+1); i++){ // 1000 * 1000
            for(int j = max(1, col-1); j <= min(1000, col+1); j++){

                if(i == row || j == col){ // ������Ƿ�§
                    if(dist[i][j] == -1 || dist[i][j] == -2){
                        //cout << i << " " << j << "\n";

                        if(dist[i][j] == -2){ // ����
                            dist[i][j] = dist[row][col] +1 ; // ��ҵç��������� --> �ź������ 1
                        } else {
                            dist[i][j] = dist[row][col]; // ������������ �����ź --> �����
                        }
                        if(i == 1000 || j == 1000){
                            dig = min(dig, dist[i][j]);
                            //cout << dig << "\n";
                        } // ��Ҷ֧�ͺ����
                        q.push({i, j});

                    }

                }
            }
        }


    }
    return dig;

}


int main()
{
    cin >> N >> a >> b;
    int x,y;
    for(int i = 1; i <= 1000; i++){
        for(int j = 1; j <= 1000 ; j++){
            dist[i][j] = -1;
        }
    }

    for(int i = 0 ; i < N ; i++){
        cin >> x >> y;
        dist[x][y] = -2; // ����
    }

    cout << BFS();

    return 0;
}
