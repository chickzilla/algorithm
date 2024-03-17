#include <iostream>
#include <vector>

using namespace std;

/*5 9
2 8 3 1 4*/
int arr[9999];
int sum,n, k, sum_all = 0;
bool check = false;


void bf(vector<int> &ans, int len, int select, int sum_cur){

    if(check) return;

    if(sum_cur == k && select >= 1){
        for(int i = 0; i < len; i++){
            if(ans[i] == 1) {
                check = true;
                cout << arr[i] << " ";
            }
        } cout << "\n";

    }

    else if(len < n){

        if(sum_cur <= k){

            ans[len] = 0;
            bf(ans, len+1 ,select,  sum_cur);

            ans[len] = 1;
            bf(ans, len+1, select+1, sum_cur + arr[len]);


        }


    }
}

int main()
{
    cin >> n >> k;

    for(int i = 0 ; i < n; i++){
        cin >> arr[i];
        sum_all += arr[i];
    }

    vector<int> ans(n);
    bf(ans, 0, 0, 0);
    if(!check) {
        cout << "No answer!!";
    }

    return 0;
}
