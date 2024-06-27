//同余模定理
/*
a≡ b(mod d)
1) a≡a(mod d) 
2) a≡b(mod d)→b≡a(mod d) 
3) (a≡b(mod d),b≡c(mod d))→a≡c(mod d)

如果a≡x(mod d),b≡m(mod d),则 
4) a+b≡x+m （mod d） 
5) a-b≡x-m(mod d) 
6) a*b≡x*m(mod d )
应用 加减乘，不适用于除法
(a+b)%c=(a%c+b%c)%c;
(a-b)%c=(a%c-b%c)%c; 
(a*b)%c=(a%c*b%c)%c;
*/
/*
题目描述：
S(n)=n^5
求S(n)除以3的余数
输入描述：
每行输入一个整数n，(0 < n < 1000000) 
处理到文件结束
输出描述：
输出S(n)%3的结果并换行

S(n)%3=(n^5)%3=(n*n*n*n*n)%3=((n%3)*(n%3)*(n%3)*(n%3)*(n%3))%3
*/

#include<stdio.h>  
#include<iostream>  
using namespace std;  
  
int main() {  
    long long int n;  
    while(~scanf("%lld",&n)) {  
        long long int s=n;  
        // 同余模定理：  
        for(int i=1;i<5;i++) {  
            s=((s%3)*(n%3));  
        }  
        printf("%lld\n",s%3);  
    }  
    return 0;  
}  