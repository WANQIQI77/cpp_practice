#include <iostream>  
#include <string>  
#include <map>  
using namespace std;  
  
int main(){  
    int n,q,x;  
    map<int, int> M;//����һ��mapӳ��  
    scanf("%d", &n);  
    for (int i = 0; i < n; i++) {  
        scanf("%d", &x);  
        M[x]++;//��¼������x�ж��ٸ�  
    }  
    scanf("%d", &q);  
    for (int i = 0; i < q; i++) {  
        scanf("%d", &x);  
        if (M[x] == 0) {//���x�ĸ���Ϊ0  
            printf("no\n");  
            M[x]++;//��x���뵽������  
        }  
        else printf("find\n");  
    }  
    return 0;  
} 