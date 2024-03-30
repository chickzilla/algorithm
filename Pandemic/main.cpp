#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// �� BFS ����ҷء�ѧ��Ѵ����������������� queue ��͹
// mark �ѧ��Ѵ������������Ҩ����� �������Һ͡������ҵԴ�������
// ��  queue �ѹ�á����Ѻ�ѹ��� x �ա�ѹ�ѹ��� x+1
using namespace std;
int mark[501][501];
int r,c,t;
queue<vector<int>> q; // �� vector ���� �繾ԡѴ��� 2 ��� ���ѹ��� x
queue<vector<int>> q2; // �����������Ѻ�ѹ��� x+1

// �͡��� q ������������繵���˹
int BFS(queue<vector<int>> &q_use, bool isQ_one){
    int ans = 0;

    while(q_use.size() > 0){
        vector<int> vertice = q_use.front();
        q_use.pop();
        int row = vertice[0];
        int col = vertice[1];



        for(int i = max(0,row-1); i < min(r, row+2); i++){
            for(int j = max(0, col-1); j < min(c, col+2); j++){
                // ������Ƿ�§
                if(i == row || j == col){
                    if(mark[i][j] == 0){
                        // ��� q ��������ѹ����
                        //cout << i << " " << j << " | ";
                        if(isQ_one){
                            q2.push({i, j});
                        } else {
                            q.push({i, j});
                        }
                        // maek ��ҵԴ ���������
                        mark[i][j] = 1;
                        ans++;
                    }
                }
            }
        }
    }
    cout << "\n";

    return ans;
}


int main()
{
    cin >> r >> c >> t;
    int x;
    int ans = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> x;
            if(x != 0){
                mark[i][j] = x;
                if( x == 1){
                    // ��ҵԴ��������� queue ��͹ + �ӹǹ�Դ����
                    q.push({i,j});
                    ans++;
                }
            }
        }
    }

    for(int i = 1; i <= t; i++){
        if(q.empty()){
            ans += BFS(q2, false);
        }else {
            ans += BFS(q, true);
        }
         //cout << "day " << i << " " << ans << "\n";
    }
    cout << ans;


    return 0;
}
