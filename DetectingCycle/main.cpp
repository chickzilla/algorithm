#include <iostream>

using namespace std;

// ����Ҩش x � �ش x ����� ( visit = true ������������ false )
// ��check �ء node �ҡ�ء Graph

int G[1001][1001]; // �纡�ҿ
bool visited[1001];
int from[1001];
int T, n, e, a, b;


void dfs(int vertice, bool &isFirst){
    // is First --> �͡����繤���á��� ( �ѹ���Ẻ true ����ѹ�ͧ�����á )
    if(!isFirst){
        visited[vertice] = true;
    }else {
        isFirst = false;
    }
    for(int i = 0; i < n; i++){

        // If adj with vertice and visted
        // �ѹ�����礡ó�仡�Ѻ �ͧ�֡�Ҿ�� 2 node �ѹ������� Circular ��ҡѹ�óչ�� ���� Node �á �������� False
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

            // ��ҵ���ѹ����ö�ҵ���������ҵ���ѹ�����������ѹ�ͧ��
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
