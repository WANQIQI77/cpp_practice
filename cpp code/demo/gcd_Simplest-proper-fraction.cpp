#include <stdio.h>  
  
int gcd(int a, int b) {  
    if(b==0) return a;  
    else return gcd(b, a%b);  
}  
int main() {  
    int buf[605];  
    int ans, n;  
    while(scanf("%d", &n)!=EOF) {  
        for(int i=0; i<n; i++)  
            scanf("%d", &buf[i]);  
        ans=0;//´ð°¸¸öÊý  
        for(int i=0; i<n; i++)  
            for(int j=i+1; j<n; j++)  
                if (gcd(buf[i], buf[j])==1) ans++;  
        printf("%d\n", ans);  
    }  
    return 0;  
}  