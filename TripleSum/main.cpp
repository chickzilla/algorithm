#include <iostream>
#include <vector>

using namespace std;

int start; int stop; int sum;int n;

bool solve(vector<int> &number , int &q){
    for(int i =0;i <n-2; i++){
        start = i+1;
        stop = n-1;

        while( start < stop){
          sum = number[start] + number[stop] + number[i];
          if(sum == q){
            return true;
          } else if(sum > q) {stop--;}
          else { start++;}
        }
    }
    return false;
}


int main()
{
    int m; int q;
    cin >> n >> m;
    vector<int> numbers(n);
    for(int i = 0; i < n; i++) {cin >> numbers[i];}
    while(m--){
        cin >> q;
        if(solve(numbers, q)){
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }


    return 0;
}
