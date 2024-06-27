//最长公共子序列
/*
dp[i, j] = 0 	if i = 0 or j = 0
dp[i, j] = dp[i - 1, j - 1] + 1	if i, j > 0 and ai = bj
dp[i, j] = max{dp[i, j - 1], dp[i - 1, j]}	if i, j > 0 and ai != bj
*/
#include <bits/stdc++.h>  
using namespace std;  
  
int dp[101][101];  
int main() {  
    string a, b;  
    memset(dp, 0, sizeof(dp));  
    cin >> a >> b;  
    int lena = a.size();  
    int lenb = b.size();  
    for(int i = 1; i <= lena; ++i) {  
        for (int j = 1; j <= lenb; ++j) {  
            if(a[i - 1] == b[j - 1]) {  
                dp[i][j] = dp[i - 1][j - 1] + 1;  
            } else {  
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  
            }  
        }  
    }  
    cout << dp[lena][lenb] << endl;  
    return 0;  
}  