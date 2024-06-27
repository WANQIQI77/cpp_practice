/*小 A 同学现在被困在了一个迷宫里面，他很想从迷宫中走出来，他可以 向上、向下、向左、向右移动、每移动一格都需要花费 1 秒的时间，不能够走到 边界之外。假设小 A 现在的位置在 S，迷宫的出口在 E，迷宫可能有多个出口。 问小 A 想要走到迷宫出口最少需要花费多少秒？
输入描述：
有多组测试数据。
第一行输入两个正整数 H（0 < H <= 100）和 W（0 < W <= 100），分别表示迷
宫的高和宽。
接下来 H 行，每行 W 个字符（其中‘*’表示路，‘#’表示墙，‘S’表示小 A
的位置，‘E’表示迷宫出口）。
当 H 与 W 都等于 0 时程序结束。
输出描述：
输出小 A 走到迷宫出口最少需要花费多少秒，如果永远无法走到出口则输出“-1”。
输入样例#:
3 3
S*#
**#
#*E
0 0
输出样例#:
4
*/

#include <bits/stdc++.h>  
using namespace std;  
  
const int maxn = 100 + 5;
char mpt[maxn][maxn];
int vis[maxn][maxn];//标记是否访问  
//上下左右四个方向
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
struct node {
    int x, y;
    int step;
};

//使用广度优先搜索求解  
int bfs(int sx, int sy) {
    memset(vis, 0, sizeof(vis));
    //使用队列来维护一层层发散的优先级  
    queue<node> q;
    q.push(node{sx, sy, 0});
    vis[sx][sy] = 1;
    //记录最短路径的长度
    int ans = -1;
    while(!q.empty()) {
        node now = q.front();
        q.pop();
        if (mpt[now.x][now.y] == 'E') {//找到终点  
            ans = now.step;
            break;
        }
        for (int i = 0; i < 4; i++) {//上下左右四个方向  
            int nx = now.x + dir[i][0];
            int ny = now.y + dir[i][1];
            //下一步可以走且没有被访问过，入队列
            if ((mpt[nx][ny] == '*' || mpt[nx][ny] == 'E')&&vis[nx][ny] == 0) {
                q.push(node{nx, ny, now.step + 1});
                vis[nx][ny] = 1;
            }
        }
    }
    return ans;
}

int main() {
    int h, w;
    while (scanf("%d%d", &h, &w) != EOF) {
        if (h == 0 && w == 0) break;
        int sx = 0, sy = 0;
        memset(mpt, 0, sizeof(mpt));
		memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= h; i++) {
            scanf("%s", mpt[i] + 1);
            for (int j = 1; j <= w; j++) {
                if (mpt[i][j] == 'S') {
                    sx = i, sy = j;//记录起点坐标  
                }
            }
        }
        int ans = bfs(sx, sy);
        printf("%d\n", ans);
    }
    return 0;
}