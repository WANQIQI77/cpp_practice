/*С A ͬѧ���ڱ�������һ���Թ����棬��������Թ����߳����������� ���ϡ����¡����������ƶ���ÿ�ƶ�һ����Ҫ���� 1 ���ʱ�䣬���ܹ��ߵ� �߽�֮�⡣����С A ���ڵ�λ���� S���Թ��ĳ����� E���Թ������ж�����ڡ� ��С A ��Ҫ�ߵ��Թ�����������Ҫ���Ѷ����룿
����������
�ж���������ݡ�
��һ���������������� H��0 < H <= 100���� W��0 < W <= 100�����ֱ��ʾ��
���ĸߺͿ�
������ H �У�ÿ�� W ���ַ������С�*����ʾ·����#����ʾǽ����S����ʾС A
��λ�ã���E����ʾ�Թ����ڣ���
�� H �� W ������ 0 ʱ���������
���������
���С A �ߵ��Թ�����������Ҫ���Ѷ����룬�����Զ�޷��ߵ������������-1����
��������#:
3 3
S*#
**#
#*E
0 0
�������#:
4
*/

#include <bits/stdc++.h>  
using namespace std;  
  
const int maxn = 100 + 5;
char mpt[maxn][maxn];
int vis[maxn][maxn];//����Ƿ����  
//���������ĸ�����
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
struct node {
    int x, y;
    int step;
};

//ʹ�ù�������������  
int bfs(int sx, int sy) {
    memset(vis, 0, sizeof(vis));
    //ʹ�ö�����ά��һ��㷢ɢ�����ȼ�  
    queue<node> q;
    q.push(node{sx, sy, 0});
    vis[sx][sy] = 1;
    //��¼���·���ĳ���
    int ans = -1;
    while(!q.empty()) {
        node now = q.front();
        q.pop();
        if (mpt[now.x][now.y] == 'E') {//�ҵ��յ�  
            ans = now.step;
            break;
        }
        for (int i = 0; i < 4; i++) {//���������ĸ�����  
            int nx = now.x + dir[i][0];
            int ny = now.y + dir[i][1];
            //��һ����������û�б����ʹ��������
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
                    sx = i, sy = j;//��¼�������  
                }
            }
        }
        int ans = bfs(sx, sy);
        printf("%d\n", ans);
    }
    return 0;
}