#include <iostream>  
#include <string>  
#include <map>  
using namespace std;  
  
int main(){  
    int n,q,x;  
    map<int, int> M;//定义一个map映射  
    scanf("%d", &n);  
    for (int i = 0; i < n; i++) {  
        scanf("%d", &x);  
        M[x]++;//记录集合中x有多少个  
    }  
    scanf("%d", &q);  
    for (int i = 0; i < q; i++) {  
        scanf("%d", &x);  
        if (M[x] == 0) {//如果x的个数为0  
            printf("no\n");  
            M[x]++;//将x加入到集合中  
        }  
        else printf("find\n");  
    }  
    return 0;  
} 