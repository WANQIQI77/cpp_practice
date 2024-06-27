//最长上升子序列
#include <bits/stdc++.h>  
using namespace std;  
  
int dp[1001], a[1001], n;  
  
int LIS_nn() {  
    int ans = 0;  
    for (int i = 1; i <= n; ++i) {  
        dp[i] = a[i];  
        for (int j = 1; j < i; ++j) {  
            if (a[j] < a[i]) {  
                dp[i] = max(dp[i], dp[j] + a[i]);  
            }  
        }  
        ans = max(ans, dp[i]);  
    }  
    return ans;  
}  
  
int main() {  
    while (cin >> n) {  
        for (int i = 1; i <= n; ++i) {  
            cin >> a[i];  
        }  
        cout << LIS_nn() << endl;  
    }  
    return 0;  
}  