#include <iostream>
#include <vector>
// check ��ҵ�ǡ�͹˹�ҵ�� constract �ѹ����ѧ
using namespace std;

vector<bool> use(1001, false); // ������͡��ҵ���˹�������
vector<vector<int>> adjList(1001, vector<int>());
int n,e;


string check(vector<int> &solve){
    for(int i = 1; i <= n; i++){
        int vertice = solve[i];

        // for loop ��ҵ�Ƿ���ͧ�ӡ�͹�ѹ ������ѧ
        for(auto &before : adjList[vertice]){
            //cout << "FAIL " << vertice << " " << before << "\n";
            if(use[before] == false){
                return "FAIL";
            }
        }
        use[vertice] = true;
    }
    return "SUCCESS";
}

int main()
{
    cin >> n >> e;
    int a,b;

    for(int i = 0; i < e; i++){
        cin >> a >> b;
        adjList[b].push_back(a);// ����Ƿ���ҷ��������� �֧�ӵ�������
    }

    vector<int> solve(n+1);
    for(int i = 0; i < 5; i++){
        for(int j = 1; j <= n; j++){
            cin >> solve[j];
            use[j] = false;
        }
        cout << check(solve) << "\n";
    }

    return 0;
}
