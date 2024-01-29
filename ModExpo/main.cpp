#include <iostream>

using namespace std;

int tmp;
int dc(int &p, int q, int &k){
    if(q == 1) {
        return p % k;
    } else {
        if(q % 2 == 0){
            tmp = dc(p, q/2, k);
            return (tmp * tmp) % k;
        } else {
            tmp = dc(p, q/2, k);
            return (((tmp*tmp)%k)*(p%k))%k;

        }
    }
}

int main()
{
    int p,q,k;
    cin >> p >> q >> k;
    cout << dc(p, q, k);

    return 0;
}
