//最大子段和
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
        maxx = a[0];//最小的情况就是不选那么答案就是0  
        for(int i = 1; i < n; i++){  
            dp[i] = max(dp[i-1] + a[i], a[i]);  
            if(maxx < dp[i]) {//如果累加到更大的值则更新  
                maxx = dp[i];  
            }  
        }  
        cout << maxx << endl;  
    }  
   return 0;  
}  