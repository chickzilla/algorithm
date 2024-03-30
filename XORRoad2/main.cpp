#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int beatiful[2005];
int dist[2005];
bool taken[2005];

int main()
{
    cin >> n;
    for(int i = 0; i< n; i++){
        cin >> beatiful[i];
        dist[i] = -1;
        taken[i] = false;
    }

    priority_queue<pair<int,int>> q;
    q.push({0,0});
    dist[0] = 0;

    while(q.size() > 0){
        int beati = q.top().first;
        int vertice = q.top().second;
        taken[vertice] = true;
        q.pop();



        for(int i = 0; i < n; i++){
            int xor_val = beatiful[i] ^ beatiful[vertice];

            if(taken[i] == false && xor_val > dist[i]){
                //cout << "vertice " << vertice << " " << i << " dist " << xor_val << "\n";
                q.push({xor_val, i});
                dist[i] = xor_val;
            }
        }
    }

    long long ans = 0;
    for(int i = 0; i < n; i++){
         ans += dist[i];
    }
    cout << ans;


    return 0;
}
