//拓扑排序模板
#include <bits/stdc++.h>  
using namespace std;  
  
const int maxn = 505;  
bool mpt[maxn][maxn];  
int lev[maxn];  //存储每个顶点入度
vector<int> v[maxn];  //存储邻接顶点
priority_queue<int, vector<int>, greater<int> > q;  //存储入度为0的顶点
//拓扑排序  
void topo(int n) {  
    for (int i = 1; i <= n; i++) {  
        if (!lev[i]) q.push(i);  //队列里面存的是入度为0的点
    }  
    int flag = 0; //统计出队的元素个数 
    while(!q.empty()) {  
        int now = q.top();  
        q.pop();  
        if (flag) printf(" %d", now);  
        else printf("%d", now);  
        flag++;  
        for (int i = 0; i < v[now].size(); i++) {  
            int next = v[now][i];  
            lev[next]--;  
            if (!lev[next]) q.push(next);  
        }  
    }  
    if (flag != n) {  
        printf("这个图有环、并没有拓扑排序\n");  
    }  
}  
  
int main() {  
    int n, m;  
    while(scanf("%d%d", &n, &m) != EOF) {  
        memset(mpt, 0, sizeof(mpt));  
        for (int i = 1; i <= m; i++) {  
            int a, b;  
            scanf("%d%d", &a, &b);  
            mpt[a][b] = 1;  
        }  
        for (int i = 1; i <= n; i++) {  
            v[i].clear();  
            for (int j = 1; j <= n; j++) {  
                if (mpt[i][j]) {  
                    v[i].push_back(j);  
                    lev[j]++;  
                }  
            }  
        }  
        topo(n);  
        printf("\n");  
    }  
    return 0;  
}  