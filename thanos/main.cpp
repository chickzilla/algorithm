#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;
vector<int> heroes;
long long int A,B;

int destroy(long long int start, long long int stop){
    if(start < stop){
        //หาพลังเมื่อทำลายทั้งหมด
        // หาจำนวน heroes
        auto start_he = lower_bound(heroes.begin(),heroes.end(), start) - heroes.begin() ;
        auto stop_he = upper_bound(heroes.begin(), heroes.end(), stop) - heroes.begin();

        long long int number_hero = stop_he - start_he;

        // ถ้า heroes > 0 ใช้พบังกับ B ถ้าไม่ A
        long long int power_All = number_hero > 0 ? (number_hero * B * (stop - start+1) ) : A;

        long long int m = start + stop >> 1;

        long long int power_left = destroy(start, m);
        long long int power_right = destroy(m+1, stop);
        long long int power_child = power_left + power_right;


        //เทียบว่าทำลายหมดกับแยกอันไหนดีกว่า
        return power_All < power_child? power_All : power_child;
    } else if (start == stop){

        // เอามาหาจำนวน hero ที่ซ้ำ

        auto start_he = lower_bound(heroes.begin(),heroes.end(), start) - heroes.begin() ;
        auto stop_he = upper_bound(heroes.begin(), heroes.end(), stop) - heroes.begin();

        long long int power_one = 0;
        if(binary_search(heroes.begin(), heroes.end(), start)) {
            power_one = B * (stop_he -start_he);
        } else {
            power_one = A;
        }
        return power_one;
    }


}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    long long p,k;
    cin >> p >> k >> A >> B;
    heroes.resize(k);
    for(int i = 0; i <k; i++){cin>> heroes[i];}
    sort(heroes.begin(), heroes.end());
    cout << destroy(1,pow(2,p));
    return 0;
}
