#include <iostream>
#include <cmath>
using namespace std;

int gcd(int m, int n);
int get_stoi(int &num, string &st);

int main() {
    cout << "ŷ������㷨��\n";
    string x, y;
    int m, n;
    cout << "��������Ȼ�� m��";
    if(get_stoi(m, x) != 0) {
        cout << "�������ʹ���\n";
        return 1;
    }
    cout << "��������Ȼ�� n��";
    if(get_stoi(n, y) != 0) {
        cout << "�������ʹ���\n";
        return 1;
    }
    m = gcd(m, n);
    if(m != 0)
        cout << "���ǵ����Լ���ǣ�" << m << endl;
    else
        cout << "����û�����Լ����" << endl;
    return 0;
}

int gcd(int m, int n) {
    if(n == 0 || m == 0)
        return 0;
    int t = m % n;
    while(t != 0) {
        m = n;
        n = t;
        t = m % n;
    }
    return n;
}

int get_stoi(int &num, string &st) {
    try {
        cin >> st;
        num = stoi(st);
        if(num < 0)
            return 1;
    } catch(invalid_argument& e) {
        return 1;
    }
    return 0;
}
