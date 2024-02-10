#include <iostream>

using namespace std;

int length[10000];
char solve(int n, int k){
    // check ว่าอยู่ในช่วงไหน
    if(k == 0){
        return n % 3 == 1 ? 'g' : 'a';
    } else {
        if(n <= length[k-1]){
            return solve(n, k-1);
        }
        n -= length[k-1];

        if(n > k+3) {
            return solve(n - (k+3), k-1);
        } else {
            return n == 1 ? 'g' : 'a';
        }

    }
}

int main()
{
    // คิดความยาวของคำว่า ga ในแต่ละ g(k) แล้ว dc ดว่าควรตกช่วงไหน
    int n;
    cin >> n;
    char ans;
    for(int i = 0 ; i <n ; i++){
        // ใส่ค่าความยาว ga ในแต่ละ k หยุดตัวที่ >= n
        // แล้วเอาค่า k(aka i) นั้นไปคิด
        length[i] = (i == 0 ? 3 : (length[i-1] * 2) + (i + 3));
        //cout << length[i] << "\n";
        if(length[i] >= n){
            ans = solve(n, i);
            break;
        }
    }
    cout << ans;


    return 0;
}
