//ͬ��ģ����
/*
a�� b(mod d)
1) a��a(mod d) 
2) a��b(mod d)��b��a(mod d) 
3) (a��b(mod d),b��c(mod d))��a��c(mod d)

���a��x(mod d),b��m(mod d),�� 
4) a+b��x+m ��mod d�� 
5) a-b��x-m(mod d) 
6) a*b��x*m(mod d )
Ӧ�� �Ӽ��ˣ��������ڳ���
(a+b)%c=(a%c+b%c)%c;
(a-b)%c=(a%c-b%c)%c; 
(a*b)%c=(a%c*b%c)%c;
*/
/*
��Ŀ������
S(n)=n^5
��S(n)����3������
����������
ÿ������һ������n��(0 < n < 1000000) 
�����ļ�����
���������
���S(n)%3�Ľ��������

S(n)%3=(n^5)%3=(n*n*n*n*n)%3=((n%3)*(n%3)*(n%3)*(n%3)*(n%3))%3
*/

#include<stdio.h>  
#include<iostream>  
using namespace std;  
  
int main() {  
    long long int n;  
    while(~scanf("%lld",&n)) {  
        long long int s=n;  
        // ͬ��ģ����  
        for(int i=1;i<5;i++) {  
            s=((s%3)*(n%3));  
        }  
        printf("%lld\n",s%3);  
    }  
    return 0;  
}  