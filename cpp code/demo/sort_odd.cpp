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
  
bool cmp(int a,int b){  
    if(a % 2 == b % 2)//���ͬ��ͬż  
        return a < b;//ֱ�Ӵ�С��������  
    else//�����ż�Բ�ͬ  
        return (a%2) > (b%2);//������ż��ǰ  
}  
int main() {  
    int n;  
    int a[1005] = {0};  
    cin >> n;  
    for (int i = 0; i < n; i++) {  
        cin >> a[i];  
    }  
    sort(a, a+n, cmp);  
    for(int i = 0; i < n; i++) {  
        cout << a[i] << " ";  
    }  
    cout << endl;  
    return 0;  
} 