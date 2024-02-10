#include <iostream>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m ,k;
    cin >> n >> m >>k;
    long long area[n];
    long long budget[n];
    long long x;
    for(long long i = 0;i <n; i++){
        cin >> x;
        if(i == 0){
            area[i] = x;
            budget[i] = x+k;
        } else {
            area[i] = area[i-1] + x;
            budget[j] = budget[j-1] + area[i] + k;
        }
    }

    long long a,b;


    return 0;
}
