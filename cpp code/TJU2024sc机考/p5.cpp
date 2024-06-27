#include <cstring>
#include <stdio.h>  
#include <string.h>  
#include <math.h>  
#include <stdlib.h>  
#include <time.h>  
#include <algorithm>  
#include <iostream>  
#include <queue>  
#include <stack>  
#include <type_traits>
#include <vector>  
#include <string>  
#include <climits>
#include <iomanip>
#include <bitset>
using namespace std; 
/*
小Z在处理一个特殊的最短路径问题，在无向图中有部分边在最初始时是上锁没法通过的，当他拿到位于节点
k的钥匙后，这些边就可以通过了。通过一条边的花费为边权值，他想知道从节点1走到节点n的最小花费是多少。
*/
/*
多组样例输入，第一行输入一个整数T表示样例数
对于每个样例，第一行包含两个整数n, m, k,图一共n个节点m条边，节点编号从1到n,钥匙在节点k。
接下来m行包含四个整数，s t w v,表示有一条从s到t的边，权重为w，如果v为0则表示不需要钥匙就可以通行，
如果是1则表示该边需要拿到钥匙后才能通行。
*/
/*
输出
对于每组样例，输出一个整数表示从1到n的最短路，如果不能到达，则输出-1。
*/
int dfs(int a, int b, vector<vector<int>>& W, vector<vector<int>>& V, vector<vector<int>>& g, int k, vector<bool>& visited) {
    if (a == b) return 0; // 如果已经到达目标节点，返回0
    visited[a] = true; // 标记当前节点为已访问
    int shortest_W = INT_MAX;
    for (int i = 0; i < g[a].size(); i++) {
        int next = g[a][i];
        if (!visited[next]) { // 避免重复访问
            if (V[a][next] == 0 || (V[a][next] == 1 && k == 1)) { // 如果边可以通行
                int dist = W[a][next] + dfs(next, b, W, V, g, k, visited);
                shortest_W = min(shortest_W, dist);
            }
        }
    }
    visited[a] = false; // 回溯时取消当前节点的访问标记
    return shortest_W == INT_MAX ? -1 : shortest_W; // 如果没有找到路径，返回-1
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> g(n + 1);
        vector<vector<int>> W(n + 1, vector<int>(n + 1, INT_MAX));
        vector<vector<int>> V(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            int s, t, w, v;
            cin >> s >> t >> w >> v;
            g[s].push_back(t);
            g[t].push_back(s);
            W[s][t] = w;
            W[t][s] = w;
            V[s][t] = v;
            V[t][s] = v;
        }

        vector<bool> visited(n + 1, false); // 用于标记节点是否已访问
        int shortest_W1 = dfs(1, n, W, V, g, 0, visited);
        int shortest_W2 = dfs(1, k, W, V, g, 0, visited);
        int shortest_W3 = dfs(k, n, W, V, g, 1, visited);
        if (shortest_W2 != -1 && shortest_W3 != -1) { // 确保1到k和k到n的路径都存在
            shortest_W2 += shortest_W3;
        } else {
            shortest_W2 = INT_MAX; // 如果任一路径不存在，设置为无穷大
        }
        int shortest_W = min(shortest_W1, shortest_W2);
        cout << (shortest_W == INT_MAX ? -1 : shortest_W) << endl;
    }
}