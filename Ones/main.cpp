#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int q[99999];

int dc(int n, int q, int digit){
    // trivially
    if( n <= 11){
        if ( n <= 6) {
            return n;
        } else {
            return 2 + (11-n);
        }
    } else {
        cout << n << " " << q << " " << digit << "\n";

        // ดูว่าลงตัวกี่ครั้ง
        int k = n/q;
        if(n % q == 0) {
            return k * digit;
        }

        // ex 1111110 = 11111111 - 1
        // find min q_k - n and n - q_k-1
        //q_k-1
        int r1 = k*digit + dc(n - q*k, q/10, digit-1);
        cout << "r1 ---- " << r1 << "\n";

        //q_k --> digit - ตลอดไม่งั้น loop forever
        int r2 = digit + dc(q-n, q/10, digit-1);
        cout << "r2---- " << r2 << "\n";
        return min(r1,r2);
        //return r1;






    }



}


int main()
{
    int n;
    cin >> n;
    // create q which most q <= n
    int q = 1;
    int digit = 1;
    while( n >= q){
        q = q*10 + 1;
        digit++;
    }

    //cout << q;
    cout << dc(n,q,digit);
    return 0;
}
