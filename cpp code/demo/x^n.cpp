#include <bits/stdc++.h>  
using namespace std;  
  
typedef long long ll;  
ll mod_pow(ll x, ll y, ll mod) {  
    ll res = 1;  
    while (y > 0) {  
        //������������λΪ1�������x^(2^i)  
        //���y�ĵ�ǰ���λ�Ƿ�Ϊ1����y��������
        if (y & 1) res = res * x % mod;  
        x = x * x % mod;  // ��xƽ��  
        //y��2
        y >>= 1;  
    }  
    return res;  
}  
  
int main() {  
    ll x, n;//ע��x*x�ᳬ��int��Χ  
    scanf("%lld%lld", &x, &n);  
    printf("%lld\n", mod_pow(x, n, 233333));  
    return 0;  
}  