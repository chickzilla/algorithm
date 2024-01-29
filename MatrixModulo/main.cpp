#include <iostream>
#include <vector>

using namespace std;
vector<int> tmp(4);
vector<int> mul_vec(4);
int k;

vector<int> mod_mat(vector<int> &M){
    for(int i =0;i < 4; i++){
        M[i] = M[i]%k;
    }
    return M;
}


vector<int> mat_mul(const vector<int> &M,const vector<int> &N){
     vector<int> r(4);

    r[0] = M[0] * N[0] + M[1]*N[2];
    r[1] = M[0] * N[1] + M[1]*N[3];
    r[2] = M[2] * N[0] + M[3]*N[2];
    r[3] = M[2] * N[1] + M[3]*N[3];

    for(int i = 0; i < 4; i++) r[i] = r[i] % k;

    return r;
}

vector<int> dc(vector<int> MN, int n){
    if(n == 1) {
        return mod_mat(MN);
    } else {
        if(n % 2 == 0) {
            tmp = dc(MN, n/2);
            return mat_mul(tmp, tmp);
        } else {
            tmp = dc(MN, n/2);
            mul_vec = mat_mul(tmp, tmp);
            return mat_mul(mul_vec, MN);
        }
    }
}
int main()
{
    int n;
    cin >> n >> k;
    vector<int> MN(4);
    for(int i =0; i < 4; i++) {cin >> MN[i];}

    vector<int> ans = dc(MN, n);
    for(int i = 0; i < 4; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
