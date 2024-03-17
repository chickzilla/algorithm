#include <iostream>

using namespace std;

// หาว่าจุด x ไป จุด x ได้ไหม ( visit = true โดยให้แต่เดิมเป็น false )
// โดยcheck ทุก node จากทุก Graph

int G[1001][1001]; // เก็บกราฟ
bool visited[1001];
int from[1001];
int T, n, e, a, b;


void dfs(int vertice, bool &isFirst){
    // is First --> บอกว่าเป็นคั้งแรกไหม ( กันที่แบบ true ตัวมันเองครั้งแรก )
    if(!isFirst){
        visited[vertice] = true;
    }else {
        isFirst = false;
    }
    for(int i = 0; i < n; i++){

        // If adj with vertice and visted
        // อันท้ายเช็คกรณีไปกลับ ลองนึกภาพมี 2 node มันก็ไม่เป็น Circular เรากันกรณีนั้น เพราะ Node แรก เราให้เป็น False
        if(G[vertice][i] == 1 && visited[i] == false && from[vertice] != i){
            from[i] = vertice;
            dfs(i, isFirst);
        }
    }
    return;
}

int main()
{
    cin >> T;
    for(int t = 0; t < T; t++){
        cin >> n >> e ; // input
        int isCycle = false; // check

        for(int i = 0 ; i < n; i++){ // innit matrix 0
            for(int j = 0; j < n; j++){
                G[i][j] = 0;
            }
        }

        while(e--){    // Add matrix
            cin >> a >> b;
            G[a][b] = 1;
            G[b][a] = 1;
        }

        for(int i = 0; i < n; i++){
            for(int i = 0 ; i< n; i++){ // created visited for each vertice
                visited[i] = false;
                from[i] = -1;
            }

            bool isFirst = true;
            dfs(i, isFirst);

            // ถ้าตัวมันสามารถหาตัวเชื่อมไปหาตัวมันที่ไม่ใช่ตัวมันเองได้
            if(visited[i] == true){
                isCycle = true;
                break;
            }
        }

        if(isCycle){cout << "YES" <<"\n";}
        else{cout << "NO" << "\n";}
    }

    return 0;
}
