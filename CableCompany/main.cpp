// kruskal ����
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> djSet(1001); // disJointSet
vector<int> lengthSet(1001); // ����������� Set
vector<pair<int, pair<int, int>>> edge; // keep all edge
// ����á �� weight pair ��ѧ�� center

int findSet(int x){ // ��������� set �˹
    if (djSet[x] == -1){ // ����� root
        return x;
    }
    djSet[x] = findSet(djSet[x]); // --> ��Ѻ����ѹ仨���node ���
    return djSet[x];
}

void union_ (int x, int y){
    int s1 = findSet(x);
    int s2 = findSet(y);
    if(lengthSet[s1] > lengthSet[s2]){
        djSet[s2] = s1; // ��� length set 1 ��ǡ��� ����� s2 �ҵ��
        lengthSet[s1] += lengthSet[s2]; // ����������
    } else {
        djSet[s1] = s2;
        lengthSet[s2] += lengthSet[s1];
    }
    cout << "union " << s1 << " " << s2 << "\n";
    //cout << "now " << findSet(x) << " " << findSet(y) << "\n";
}

int main()
{
    cin >> n;
    int x;
    for(int i = 0; i < n; i++){
        djSet[i] = -1; // ���ء����繾��
        lengthSet[i] = 1;
        for(int k = 0; k < n-i-1; k++){
            cin >> x;
            pair<int, int> twoCenter = make_pair(i, k+i+1);
            edge.push_back(make_pair(x, twoCenter));
        }
    }
    sort(edge.begin(), edge.end()); // sort edge

    int ans = 0;
    for(auto &e : edge){
        pair<int, int> centers = e.second;
        int u = centers.first; // node �á
        int v = centers.second; // node 2
        //cout << e.first << " " << findSet(u) << " " << findSet(v) << "\n";
        if (findSet(u) != findSet(v)){
            ans += e.first; // weight
            union_(u, v);
        }
        //cout << "Hi ";
    }
    cout << ans;


    return 0;
}
