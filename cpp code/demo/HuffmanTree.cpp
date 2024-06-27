#include <bits/stdc++.h>  
using namespace std;  
  
struct node {  
    int x;  
    node(int a) {x = a;}//构造函数方便赋值  
};  
  
//重载最小堆
//定义优先队列的比较关系 和sort的cmp类似  
bool operator < (const node& a, const node& b ){  
    return a.x > b.x;  //逻辑：a.x>b.x,a应该放在b之后
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