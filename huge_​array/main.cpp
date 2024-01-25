#include <iostream>
#include <map>

using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    map<int> freq ;
    int n; int q; int a; int b;
    cin >> n >> q;

    for(int i = 0; i< n;i++){
        cin >> a >> b;
        map[a] = b;
    }
    return 0;
}
