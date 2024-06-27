#include <bits/stdc++.h>  
using namespace std;  
#define INF 0x3f3f3f3f  
const int maxn = 105;  
int mpt[maxn][maxn];//�ڽӾ���洢ͼ  
int dist[maxn];  //��ʾ�ڵ�1���ڵ�i����̾��롣
int main(){  
    int N , M;  
    while(scanf("%d%d",&M,&N) != EOF) {  
        if (M == 0) break;  
        for (int i = 1; i <= N; i++) {  
            dist[i] = INF;//��ʼ��Ϊ�����  
            for (int j = 1; j <= N; j++) {  
                if (i == j) mpt[i][j] = 0;  
                else mpt[i][j] = INF;  
            }  
        }  
        for(int i = 0;i < M;i++) {  
            int u, v, w;  
            scanf("%d%d%d", &u, &v, &w);  
            mpt[u][v] = min(mpt[u][v], w);//��ֹ�ر�  
            mpt[v][u] = min(mpt[v][u], w);//�ر�����С��  
        }  
        int sum = 0;  
        int flag = 0;  
        for (int i = 1; i <= N; i++) dist[i] = mpt[1][i];  
        for (int i = 1; i < N; i++) {  
            int min_len = INF;  
            int min_p = -1;  //���������̽��
            for (int j = 1; j <= N; j++) {  
                if (min_len > dist[j] && dist[j] != 0) {  
                    min_len = dist[j];  
                    min_p = j;  
                }  
            }  
            if (min_p == -1) {  
                flag = 1; break;//�ж��Ƿ���������  
            }  
            sum += min_len;  
            for (int j = 1; j <= N; j++) {  //���¾���
                if (dist[j] > mpt[min_p][j] && dist[j] != 0)  
                    dist[j] = mpt[min_p][j];  
            }  
        }  
        if (flag) printf("?\n");//����������  
        else printf("%d\n", sum);  
    }  
    return 0;  
}  
 