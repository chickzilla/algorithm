#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool solve(vector<int> virus, int k){
    if(k == 2){

        // ถ้าเหลือ 4 ตัวให้ check
        int first = 0;
        int last = 0;

        for(int i =0;i < 4; i++){
            if(i <=1 && virus[i] == 1){
                first++;
            } else if(i >= 2 && virus[i] == 1){
                last++;
            }
        }
        return abs(last - first) <= 1;
    } else {

        int m = virus.size() >> 1;
        vector<int> first_half(m);
        vector<int> second_half(m);

        // คิดแบบครึ่งหน้าหลัง

        for(int i = 0; i < m; i++){
            first_half[i] = virus[i];
            second_half[i] = virus[m+i];
        }

        bool left = solve(first_half, k-1);
        bool right = solve(second_half, k-1);

        // check ว่าถูกทั้ง หน้า และ หลัง
        return right && left;
    }

}


int main()
{
    int n,k;
    cin >> n >>k;
    vector<int> virus(pow(2,k));

    while(n--){
        for(int i =0; i <virus.size(); i++){
            cin >> virus[i];
        }
        if(solve(virus, k)){
            cout << "yes" << "\n";
        } else {
            cout << "no" << "\n";
        }
    }

    return 0;
}
