#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int country[505][505];
queue<pair<int, int>> q;


int main()
{
    int R,C,T, x;
    int num = 0;
    int ans = 0;
    cin >> R >> C >> T;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> x;
            country[i][j] = x;
            if(x == 1){
                q.push({i,j});
                ans++;
            }
        }
    }

    // BFS
    for(int t = 1; t <= T ; t++){

        num = q.size();
        while(num != 0){
            pair<int,int> vertice = q.front();
            int r = vertice.first;
            int c = vertice.second;

            num--;
            q.pop();

            for(int i = max(0, r-1); i < min(R, r+2); i++){
                for(int j = max(0, c-1); j < min(C, c+2); j++){
                    if(i == r || j == c){
                        if(country[i][j] == 0){
                            country[i][j] = 1;
                            q.push({i,j});
                            ans++;
                        }
                    }

                }
            }
        }
    }
    cout << ans;



}
