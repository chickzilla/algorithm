// kruskal ปกติ
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> djSet(1001); // disJointSet
vector<int> lengthSet(1001); // ความยาวแต่ละ Set
vector<pair<int, pair<int, int>>> edge; // keep all edge
// ตัวแรก เป็น weight pair หลังเป็น center

int findSet(int x){ // หาว่าอยู่ set ไหน
    if (djSet[x] == -1){ // ถ้าเป็น root
        return x;
    }
    djSet[x] = findSet(djSet[x]); // --> ปรับให้มันไปจิ้มnode พ่อ
    return djSet[x];
}

void union_ (int x, int y){
    int s1 = findSet(x);
    int s2 = findSet(y);
    if(lengthSet[s1] > lengthSet[s2]){
        djSet[s2] = s1; // ถ้า length set 1 ยาวกว่า ก็เอา s2 มาต่อ
        lengthSet[s1] += lengthSet[s2]; // ยาวเพิ่มขึ้น
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
        djSet[i] = -1; // มห้ทุกตัวเป็นพ่อ
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
        int u = centers.first; // node แรก
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
