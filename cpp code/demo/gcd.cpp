#include <stdio.h>  
//���Լ��
int gcd(int a, int b) {  
    if (b == 0) return a;  
    else return gcd(b, a % b);  
}  
int main() {  
    int x, y;  
    scanf("%d%d", &x, &y);  
    printf("%d\n", gcd(x, y));  
} 
//��С������
/*
LCM(x, y) = x * y / GCD(x, y)
x * y = LCM(x, y) * GCD(x, y)
*/
//쳲�������ʽ
//F(n) = 1/5*(phi^n - (-1/phi)^n)
//phi = (1 + sqrt(5))/2
//F(n) = 1/sqrt(5)*[(1 + sqrt(5))/2^n - (1 - sqrt(5))/2^n]
