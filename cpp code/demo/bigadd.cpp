#include <iostream>  
#include <string>  
#include <algorithm>  
using namespace std;  
  
string Add(string a, string b) {  
    //aһֱΪλ���ϳ����ַ���  
    if (a.length() < b.length()) a.swap(b);  
  
    string result(a.length(), 0);  //��������result����Ϊ�ϳ��ַ�����  
    b.insert(0, a.length() - b.length(), '0'); //�϶̵��ַ���ǰ�油�㷽����� 
    int carry = 0;  //��λ  
    for (int i = a.length() - 1; i >= 0; i--) {  
        int sum = (a[i] - 48) + (b[i] - 48) + carry;  
        carry = sum / 10;  
        result[i] = sum % 10 + 48;  
    }  
    //����λ��Ϊ0����Ҫ��ǰ�油�Ͻ�λ  
    if (carry != 0) {  
        result.insert(result.begin(), carry + 48);  
    }  
    return result;  
}  
  
int main() {  
    string a, b;  
    while (cin >> a >> b)  
        cout << Add(a, b) << endl;  
    return 0;  
}  