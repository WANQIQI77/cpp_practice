//����Ӷκ�
#include <bits/stdc++.h>  
using namespace std;  
  
int dp[1000010];  
int a[1000010];  
long long maxx;  
int main() {  
    int n ;  
    while(cin >> n){  
        for(int i = 0; i < n; i++)  
            cin >> a[i];  
        dp[0] = a[0];  
        maxx = a[0];//��С��������ǲ�ѡ��ô�𰸾���0  
        for(int i = 1; i < n; i++){  
            dp[i] = max(dp[i-1] + a[i], a[i]);  
            if(maxx < dp[i]) {//����ۼӵ������ֵ�����  
                maxx = dp[i];  
            }  
        }  
        cout << maxx << endl;  
    }  
   return 0;  
}  