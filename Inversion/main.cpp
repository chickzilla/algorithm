#include <iostream>
#include <algorithm>

using namespace std;
int n,k;
int c = 0;
int a[100000];

void solve(int start,int stop){
    if( c == k )return;
    int m = (start + stop)/2;
    //------------------------------------------
    c++;
    int num = m-start;
    for (int i = 0 ; i < num;i++){
        swap(a[start+i],a[m+1+i]);
        cout << "swap"  << a[start+i] << " " << a[m+1+i] << "\n";
    }
    //--------------------------------------------
    if( c== k )return;
    solve(start,m);
    if( c == k)return;
    solve(m+1,stop);

    return;
}
int main(){
    cin >> n >> k;
    for(int i = 0 ; i< n ; i++){
        a[i] = i+1;
    }
    k--;
    solve(0,n-1);
    for(int i = 0 ; i< n ; i++){
        cout << a[i];
    }


}
