#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int R,C;
    cin >> R >> C;
    int fee[R][C];
    int dist[R][C];

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> fee[i][j];
            dist[i][j] = 500000;
        }
    }
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
    q.push(make_pair(0, make_pair(0,0)));
    dist[0][0] = 0;

    while(q.size() > 0){
        int r = q.top().second.first;
        int c = q.top().second.second;
        int Time = q.top().first;
        q.pop();

        for(int i = max(0, r-1); i < min(R, r+2); i++){
            for(int j = max(0, c-1); j < min(C, c+2); j++){
                if(i == r || j == c){
                    if(Time + fee[i][j] < dist[i][j]){
                        dist[i][j] = Time + fee[i][j];
                        q.push(make_pair(dist[i][j], make_pair(i,j)));
                    }
                }
            }
        }
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << dist[i][j] << " ";
        } cout << "\n";
    }







    return 0;
}
