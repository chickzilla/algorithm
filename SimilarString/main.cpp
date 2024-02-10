#include <iostream>
#include <string>
#include <cstring>

using namespace std;
char a_v[99999];
char b_v[99999];

bool dc(int startA, int startB, int len){
    if(len == 1){
        return a_v[startA] == b_v[startB];
    } else {

        int m_len = len/2;
        // left a == left b
        bool cont_1 = dc(startA, startB, m_len) && dc(startA+m_len, startB + m_len, m_len);

        bool cont_2 = dc(startA, startB + m_len, m_len) && dc(startA+m_len, startB, m_len);

        // or 2 condition
        return cont_1 || cont_2;
    }
}


int main()
{
    string a,b;
    cin >> a >> b;
    int len = a.length();

    for(int i = 0; i < len ; i++){
        a_v[i] = a[i];
        b_v[i] = b[i];
    }

    if(dc(0, 0 , strlen(a))) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
