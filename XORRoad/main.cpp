#include <iostream>
#include <vector>
#include <queue>
// use Prim ���� ��� hrushal �ѹ��ͧ�� edge ������ n*2 �ҹ
// �� Prim ���ҵ�Ƿ���ҡ�ش᷹
using namespace std;
int n;
int bestCost[2001]; // �� cost �ͧ��������§������
int value[2001]; // �纤�ҷ���� xor �ͧ��� node
bool visited[2001]; // ��������� node ������



int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> value[i];
        visited[i] = false;
        bestCost[i] = -1; // ���Ե���� inf ����Ҩ���ҵ�Ƿ���ҡ�ش ��µ���� -
    }
    priority_queue<pair<int, int>> S; // �� weight ��� node
    S.push(make_pair(0, 1)); // init node 1

    long long ans = 0;

    while(!S.empty()){
        pair<int, int> aim = S.top(); // ��� ��� weight �ҡ�ش
        S.pop();
        int vertice = aim.second;
        int beatiful = aim.first;

        // check ���������� ���� prio_queue �ѹź�����������
        if(visited[vertice] == false){ // check �ء����
            visited[vertice] = true;
            ans+= beatiful;
            // adj �ء��� (�������)
            for(int i = 1; i <= n; i++){
                int xor_val = value[i] ^ value[vertice];
                if(visited[i] == false && xor_val > bestCost[i]){ // ��� XOR ���Ǥ���ҡ����
                    bestCost[i] = xor_val; // ��Ҥ�� xor ᷹ best �ͧ�ѹ���
                    S.push(make_pair(xor_val, i)); // ��Ҥ�� best ���ŧ�
                }
            }
        }
    }
    cout << ans;

    return 0;
}
