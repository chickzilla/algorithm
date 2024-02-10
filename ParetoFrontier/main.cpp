#include <iostream>
#include <vector>

using namespace std;

vector<int> pareto(int l,int r){
    if(l == r){
        vector<int> ans;
        ans.push_back(l);
    }
    int m = l + r >> 1;
    vector<int> left = pareto(l, m);
    vector<int> right = pareto(m+1, r);

    vector<int> ans;
    while(!left.empty() || !right.empty()){
        if(left.empty()){
            for(int i =0; i < right.size() ;i++){
                ans.push_back(right[i]);
            }
        } else if (left.empty()) {
            for(int i = 0; i < left.size() ;i++){
                ans.push_back(left[i]);
            }
        } else {

        }
    }

}
int main()
{
    int n, x_i, y_i;
    cin >> n;
    vector<pair<int, int>> point;
    for(int i = 0; i < n; i++){
        cin >> x_i >> y_i;
        point.push_back(make_pair(x_i, y_i));
    }

    return 0;
}
