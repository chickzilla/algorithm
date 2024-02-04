#include <iostream>
#include <climits>


using namespace std;

int solve(int arr[], int n){
    int max_ans = INT_MIN;
    int max_cur = 0;

    for(int i = 0; i < n; i++){
        max_cur += arr[i];
        if(max_cur >= max_ans){
            max_ans = max_cur;
        }
        if(max_cur < 0){
            max_cur = 0;
        }
    }

    return max_ans;

}


int main()
{
    int n;
    cin >> n ;
    int S[n];
    for(int i =0; i < n; i++){
        cin >> S[i];
    }
    cout << solve(S, n);

    return 0;
}
