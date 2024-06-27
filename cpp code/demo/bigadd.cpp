#include <iostream>  
#include <string>  
#include <algorithm>  
using namespace std;  
  
string Add(string a, string b) {  
    //a一直为位数较长的字符串  
    if (a.length() < b.length()) a.swap(b);  
  
    string result(a.length(), 0);  //初步设置result长度为较长字符长度  
    b.insert(0, a.length() - b.length(), '0'); //较短的字符串前面补零方便计算 
    int carry = 0;  //进位  
    for (int i = a.length() - 1; i >= 0; i--) {  
        int sum = (a[i] - 48) + (b[i] - 48) + carry;  
        carry = sum / 10;  
        result[i] = sum % 10 + 48;  
    }  
    //若进位不为0，还要在前面补上进位  
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