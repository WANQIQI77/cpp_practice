#include <bits/stdc++.h>  
using namespace std;  
  
struct node {  
    int x;  
    node(int a) {x = a;}//���캯�����㸳ֵ  
};  
  
//������С��
//�������ȶ��еıȽϹ�ϵ ��sort��cmp����  
bool operator < (const node& a, const node& b ){  
    return a.x > b.x;  //�߼���a.x>b.x,aӦ�÷���b֮��
}  
  
int main()  
{  
    priority_queue<node> q;  
    int n, x;  
    cin >> n;  
    for(int i = 0;i < n;i++)  {  
        cin >> x;  
        q.push(x);  
    }  
    int ans = 0;  
    while (q.size() > 1) {  
        node num1 = q.top();  
        q.pop();  
        node num2 = q.top();  
        q.pop();  
        ans += (num1.x + num2.x);  
        q.push(node{num1.x+num2.x});  
    }  
    cout << ans;  
    return 0;  
}  