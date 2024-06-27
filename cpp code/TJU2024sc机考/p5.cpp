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
СZ�ڴ���һ����������·�����⣬������ͼ���в��ֱ������ʼʱ������û��ͨ���ģ������õ�λ�ڽڵ�
k��Կ�׺���Щ�߾Ϳ���ͨ���ˡ�ͨ��һ���ߵĻ���Ϊ��Ȩֵ������֪���ӽڵ�1�ߵ��ڵ�n����С�����Ƕ��١�
*/
/*
�����������룬��һ������һ������T��ʾ������
����ÿ����������һ�а�����������n, m, k,ͼһ��n���ڵ�m���ߣ��ڵ��Ŵ�1��n,Կ���ڽڵ�k��
������m�а����ĸ�������s t w v,��ʾ��һ����s��t�ıߣ�Ȩ��Ϊw�����vΪ0���ʾ����ҪԿ�׾Ϳ���ͨ�У�
�����1���ʾ�ñ���Ҫ�õ�Կ�׺����ͨ�С�
*/
/*
���
����ÿ�����������һ��������ʾ��1��n�����·��������ܵ�������-1��
*/
int dfs(int a, int b, vector<vector<int>>& W, vector<vector<int>>& V, vector<vector<int>>& g, int k, vector<bool>& visited) {
    if (a == b) return 0; // ����Ѿ�����Ŀ��ڵ㣬����0
    visited[a] = true; // ��ǵ�ǰ�ڵ�Ϊ�ѷ���
    int shortest_W = INT_MAX;
    for (int i = 0; i < g[a].size(); i++) {
        int next = g[a][i];
        if (!visited[next]) { // �����ظ�����
            if (V[a][next] == 0 || (V[a][next] == 1 && k == 1)) { // ����߿���ͨ��
                int dist = W[a][next] + dfs(next, b, W, V, g, k, visited);
                shortest_W = min(shortest_W, dist);
            }
        }
    }
    visited[a] = false; // ����ʱȡ����ǰ�ڵ�ķ��ʱ��
    return shortest_W == INT_MAX ? -1 : shortest_W; // ���û���ҵ�·��������-1
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

        vector<bool> visited(n + 1, false); // ���ڱ�ǽڵ��Ƿ��ѷ���
        int shortest_W1 = dfs(1, n, W, V, g, 0, visited);
        int shortest_W2 = dfs(1, k, W, V, g, 0, visited);
        int shortest_W3 = dfs(k, n, W, V, g, 1, visited);
        if (shortest_W2 != -1 && shortest_W3 != -1) { // ȷ��1��k��k��n��·��������
            shortest_W2 += shortest_W3;
        } else {
            shortest_W2 = INT_MAX; // �����һ·�������ڣ�����Ϊ�����
        }
        int shortest_W = min(shortest_W1, shortest_W2);
        cout << (shortest_W == INT_MAX ? -1 : shortest_W) << endl;
    }
}