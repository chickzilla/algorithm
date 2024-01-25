#include <iostream>
#include <vector>


using namespace std;


int n,a;
vector<int> T;
long long int label;
long long int maxTime = 10e12;
long long int m;

long long int dc(long long int label, long long int start , long long int stop){
    // binaru search �ҡ����������������ҷ��������ҹ�����������
    if(start < stop){
        m = ((long long int)start + stop) >> 1;
        long long int cou = 0; //--> ����͹�������� (�������� + ���ѧ�Թ)
        long long int mod = 0; // --> �ǡ�����ҧ������� join ��
        // --------- �Դ�ӹǹ��---
        for(int i = 0; i < n; i++){
            cou += m/T[i];
            if( m % T[i] == 0) {
                mod += 1;
            } else {
                cou += 1;
            }
        }
        // --> ���ҷ����� / �������Ф��ǡ�ѹ ---> + �Ѻ�ǡ��� mod !== 0;
        //---> mod == 0 �ҡ���˹�����������
        //cout << m << " " << mod << " " << cou << " " << "\n";

        // ��Ҥ���͹˹�ҹ��¡��� + �շ����ҧ��������;�
        if(cou < label && cou + mod >= label){
            return m;
        } else if(cou >= label){
            return dc(label, start, m);
        } else {
            return dc(label, m+1, stop);
        }
    } else {
        return 0;
    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> a;
    T.resize(n);

    for(int i = 0; i <n; i++) {cin >> T[i];}
    long long int quest;
    for(int i = 0; i <a ; i++){
        cin >> quest;
        cout << dc(quest, 0, maxTime) << "\n";
    }




    return 0;
}

