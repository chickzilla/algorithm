#include <iostream>
#include <algorithm>
#include <climits>



using namespace std;

int S = 0;

int dc(int arr[], int n){
    for(int i =0; i < n; i++){
        S += arr[i];
    }

    int max_most = INT_MIN; int max_cur = 0;
    int min_most = INT_MAX; int min_cur = 0;

    for(int i = 0 ; i < n; i++){
        max_cur = max(max_cur + arr[i], arr[i]);
        max_most = max(max_most, max_cur);

        // SUM - MIN_MOST = MAXMOST ของตัววน
        min_cur = min(min_cur + arr[i], arr[i]);
        min_most = min(min_most, min_cur);
    }

    //cout << max_most << "\n" << min_most << "\n" << S << "\n";
    if(min_most == S) return max_most;


    return max(max_most, S - min_most);


}




int main()
{
    int n;
    cin >> n;
    int arr[n];
    int S[n];
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    cout << dc(arr, n);

    return 0;
}
