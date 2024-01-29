#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
vector<int> check = {0,1};


bool solve(vector<int> virus, int k){
    if(k == 1){
        return (virus == check);
    }
    else {
        // Right �Դ��� swap �Ѻ��� swap
        // ����١�ѡ��ǡ���仵��
        int m = virus.size() >> 1;
        vector<int> half1(m);
        vector<int> half2(m);
        vector<int> half1_reverse(m);

        for(int i = 0; i<m;i++){
            half1[i] = virus[i];
            half2[i] = virus[m+i];
        }

        for(int i = 0; i < m; i++){
            half1_reverse[i] = half1[m-i-1];
        }

        // ��Ң��令Դ
        bool right = solve(half1, k-1);
        //��Ң��Ẻ swap 令Դ
        bool right_reverse = solve(half1_reverse, k-1);

        bool left = solve(half2,k-1);


        // left ����ͧ swap ��ҷ�� right ��� left �١ --> return true
        return (right && left) || (right_reverse && left);
    }
}

int main()
{
    int n,k;
    cin >> n >>k;
    vector<int> virus(pow(2, k));
    while(n--){
        for(int i =0;i < virus.size() ; i++){
            cin >> virus[i];
        }
        if(solve(virus, k)){
            cout << "yes" << "\n";
        } else {
            cout << "no" << "\n";
        }

    }
    return 0;
}
