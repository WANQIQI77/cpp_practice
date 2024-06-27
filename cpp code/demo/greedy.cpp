#include <stdio.h>  
#include <string.h>  
#include <math.h>  
#include <stdlib.h>  
#include <time.h>  
#include <algorithm>  
#include <iostream>  
#include <queue>  
#include <stack>  
#include <vector>  
#include <string>  
using namespace std; 
struct node {  
    double w, m;  
}p[1005];  
bool cmp(node a, node b) {  
    //按照每毫升的价格从低到高排序  
    return a.w/a.m < b.w/b.m;  
}  
int main(){  
    int n,x;  
    while (scanf("%d%d", &x, &n) != EOF) {  
        if (x == -1 && n == -1) break;  
        for (int i = 1; i <= n; i++) {  
            scanf("%lf%lf", &p[i].m, &p[i].w);  
        }  
        sort(p+1, p+1+n, cmp);  
        double ans = 0;  
        for (int i = 1; i <= n; i++) {  
            if (x >= p[i].w) {//如果剩余的钱能全买  
                ans += p[i].m;  
                x -= p[i].w;  
            }  
            else {//如果剩余的钱买不完这种饮料  
                ans += (p[i].m*x/p[i].w);  
                break;//到这里x已经为0了  
            }  
        }  
        printf("%.3lf\n", ans);  
    }  
    return 0;  
}