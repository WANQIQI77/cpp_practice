#include <bits/stdc++.h>  
using namespace std;  
  
const int maxn = 105;  
struct node {  
    int u, v, w;  
}edge[maxn * maxn];  
int cmp(node A, node B) {  
    return A.w < B.w;  
}  
int fa[maxn];  
int find(int x) {  
    if (x == fa[x]) return x;  
    fa[x] = find(fa[x]);  
    return fa[x];  
}  
int main(){  
    int N , M;  
    while(scanf("%d%d",&M,&N) != EOF){  
        if (M == 0) break;  
        for (int i = 0; i < M; i++) {  
            scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);            
        }  
        for (int i = 1; i <= N; i++) fa[i] = i;  
        sort(edge, edge + M, cmp);  
        int sum = 0;  
        int total = 0;  
        for (int i = 0; i < M; i++) {  
            int fx = find(edge[i].u);  
            int fy = find(edge[i].v);  
            if (fx != fy) {  
                fa[fx] = fy;  
                sum += edge[i].w;  
                total++;//统计加入边数量  
            }  
        }  
        if (total < N - 1)//不能生成树  
            printf("?\n");  
        else printf("%d\n", sum);  
    }  
    return 0;  
}  