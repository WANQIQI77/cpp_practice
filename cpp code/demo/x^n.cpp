#include <bits/stdc++.h>  
using namespace std;  
  
typedef long long ll;  
ll mod_pow(ll x, ll y, ll mod) {  
    ll res = 1;  
    while (y > 0) {  
        //如果二进制最低位为1、则乘上x^(2^i)  
        //检查y的当前最低位是否为1（即y是奇数）
        if (y & 1) res = res * x % mod;  
        x = x * x % mod;  // 将x平方  
        //y除2
        y >>= 1;  
    }  
    return res;  
}  
  
int main() {  
    ll x, n;//注意x*x会超出int范围  
    scanf("%lld%lld", &x, &n);  
    printf("%lld\n", mod_pow(x, n, 233333));  
    return 0;  
}  