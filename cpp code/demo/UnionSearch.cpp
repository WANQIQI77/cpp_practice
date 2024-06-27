/*并查集*/
/*某省调查城镇交通状况，得到现有城镇道路统计表，表中列出了每条道路直接连通的城镇。
省政府“畅通工程”的目标是使全省任何两个城镇间都可以实现交通
（但不一定有直接的道路相连，只要互相间接通过道路可达即可）。问最少还需要建设多少条道路？
输入描述：
测试输入包含若干测试用例。
每个测试用例的第1行给出两个正整数，分别是城镇数目N ( < 1000 )和道路数目M；
随后的M行对应M条道路，每行给出一对正整数，分别是该条道路直接连通的两个城镇的编号。
为简单起见，城镇从1到N编号。 */
#include <bits/stdc++.h>  
using namespace std;  
  
const int maxn = 1005;  
int fa[maxn];  //用于存储每个结点的父节点
//并查集模板  
int find(int x) { //查找一个结点的根节点 
    if (x == fa[x]) return x;  
    fa[x] = find(fa[x]); //路径压缩  fa[x]=find(fa[x]);
    return fa[x];  
}  
int main(){  
    int N , M;  
    while(scanf("%d",&N) != EOF){  
        if (N == 0) break;  
        scanf("%d",&M);  
        for (int i = 1; i <= N; i++) fa[i] = i;  
        int sum = 0;  
        for (int i = 0; i < M; i++) {  
            int x, y;  
            scanf("%d%d", &x, &y);  
            int fx = find(x);  
            int fy = find(y);  
            if (fx != fy) {  
                fa[fx] = fy;  //有边的两个并入同一个集合
                sum++;  //存储连通分量的数量
            }  
        }  
        printf("%d\n", N - sum - 1);  
    }  
    return 0;  
}  