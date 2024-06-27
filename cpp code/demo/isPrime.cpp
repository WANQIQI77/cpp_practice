#include <stdio.h>  
#include <math.h>  
  
int main() {  
    int n;  
    scanf("%d", &n);  
    if (n == 1) n++;//1不是素数  
    for (int i = n; ; i++) {  
        int flag = 0;  
        for (int j = 2; j <= sqrt(i); j++) {  
            if (i % j == 0) {//如果找到了约数  
                flag = 1;//说明不是素数  
                break;  
            }  
        }  
        if (flag == 0) {  
            printf("%d\n", i);  
            break;  
        }  
    }  
    return 0;  
}  