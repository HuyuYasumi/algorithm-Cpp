#include <iostream>
#include <vector>
using namespace std;

vector<int>* prime_num(int num);
int gcd(int m, int n);
int get_stoi(int &num, string &st);

int main() {
    cout << "�ֽ��������㷨��\n";
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

vector<int>* prime_num(int num) {
    vector<int>* v = new vector<int>();
    for (int i = 2; i <= num; i++)
        while (num != i) {
            if (num % i == 0) {
                v->push_back(i);
                num = num / i;
            } else
                break;
        }
    v->push_back(num);
    return v;
}

int gcd(int m, int n) {
    vector<int> vm = *prime_num(m);
    vector<int> vn = *prime_num(n);
    if(vm[0] == 0 || vn[0] == 0)
        return 0;
    vector<int> v_public;
    int i = 0;
    int j = 0;
    int product = 1;
    while(i < vm.size()) {
        while(j < vn.size()) {
            if(vm[i] == vn[j]) {
                v_public.push_back(vm[i]);
                j++;
                break;
            }
            j++;
        }
        if(j == vn.size())
            j = 0;
        i++;
    }
    for(int m = 0; m < v_public.size(); m ++ )
        product *= v_public[m];
    return product;
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
