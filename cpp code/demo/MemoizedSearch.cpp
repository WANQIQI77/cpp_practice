#include <bits/stdc++.h>  
using namespace std;  
  
int n,m;  
int a[105][105];  
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};  
int dp[105][105];  
// 记忆化搜索保证每个点只会计算一次  
int dfs(int x,int y){  
    if(dp[x][y]) return dp[x][y];//如果访问过则直接返回结果  
    int maxx = 1;  
    for(int i = 0; i < 4; i++){  
        int tx = x + dir[i][0];  
        int ty = y + dir[i][1];  
        if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]>a[x][y]){  
            maxx = max(maxx, dfs(tx, ty) + 1); //自底向上的  
        }  
    }  
    dp[x][y] = maxx; //记忆化  
    return maxx;  
}  
  
int main() {  
    while (cin >> n >> m) {  
        for(int i = 1; i <= n; i++)  
            for(int j = 1; j <= m; j++)  
                cin >> a[i][j];  
        int ans = 0;  
        memset(dp, 0, sizeof(dp));  
        for(int i = 1; i <= n; i++) {  
            for(int j = 1; j <= m; j++){  
                dp[i][j] = dfs(i,j);  
                ans = max(ans, dp[i][j]);  
            }  
        }  
        cout << ans << endl;  
    }  
    return 0;  
}  