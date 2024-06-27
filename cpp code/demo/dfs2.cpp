
// 石油储藏
// 题目描述：
// 有一个GeoSurvComp地质勘探公司正在负责探测地底下的石油块。这个公司在一个时刻调查一个矩形区域，并且创建成一个个的格子用来表示众多正方形块。它然后使用测定设备单个的分析每块区域，决定是否有石油。一块有石油小区域被称为一个pocket，假设两个pocket是相邻的，然后他们就是相同石油块的一部分，石油块可能非常的大并且包涵很多的pocket。你的任务就是在一个网格中存在多少个石油块。输入首先给出图的大小，然后给出这个图。*代表没有石油，@代表存在石油。输出每种情况下石油块的个数。
// 输入描述：
// 输入包含一个或多个网格。 每个网格都以包含m和n的行开始，网格中的行和列数为m和n，以单个空格分隔。 如果m = 0，则表示输入结束。 否则为1 <= m <= 100和1 <= n <=100。这之后是m行，每行n个字符（不计算行末字符）。 每个字符对应一个情节，要么是代表没有油的“ *”，要么是代表油囊的“ @”。
// 输出描述：
// 在水平，垂直或对角线上都算作相邻，输出每种情况下石油块的个数。
// 输入样例#:
// 5 5 
/*
// ****@
// *@@*@
// *@**@
// @@@*@
// @@**@
*/
// 0 0
// 输出样例#:
// 2

#include <bits/stdc++.h>  
using namespace std;  
  
const int maxn = 100 + 5;  
char mpt[maxn][maxn];  
int vis[maxn][maxn];  
int dir[8][2] = {1,0,0,-1,-1,0,0,1,1,1,1,-1,-1,1,-1,-1};  
//使用深度优先搜索求解  
int dfs(int x, int y) {  
    vis[x][y] = 1;  
    for (int i = 0; i < 8; i++) {//8个方向  
        int nx = x + dir[i][0];  
        int ny = y + dir[i][1];  
        if (mpt[nx][ny] == '@' && vis[nx][ny] == 0) {  
            dfs(nx, ny);  
        }  
    }  
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
        }  
        int ans = 0;  
        for (int i = 1; i <= h; i++) {  
            for (int j = 1; j <= w; j++) {  
                if (vis[i][j] == 0 && mpt[i][j] == '@') {  
                    ans++;  
                    dfs(i, j);  
                }  
            }  
        }  
        printf("%d\n", ans);  
    }  
    return 0;  
}  