#include <iostream>
#include <vector>

using namespace std;

int n; int m;

int bs(int start, int stop ,vector<int> &arr, int spot, int ans){
    if(start == stop){
        return (arr[start] <= spot && arr[start] > ans) ? arr[start] : ans;
    } else if ( start < stop) {
        m = (start + stop) >> 1;
        if(arr[m] <= spot) {
            return bs(m+1, stop, arr, spot, arr[m]);
        } else{
            return bs(start, m, arr, spot, ans);
        }

    }

}


int main()
{
    int qe;
    cin >> n >> qe;
    vector<int> arr(n);
    int q;
    for(int i = 0; i <n; i++){cin >> arr[i];}
    int ans = -1;
    for(int i = 0; i <qe; i++){
        cin >> q;
        cout << bs(0, n-1, arr, q, -1) << "\n";
    }


    return 0;
}
