#include <iostream>  
#include <queue>  
using namespace std;  
int main() {  
    queue<int> q;//定义一个队列  
    q.push(1);//入队  
    q.push(2);  
    q.push(3);  
    while (!q.empty()) {//当队列不为空  
        cout << q.front() << endl;//取出队首元素  
        q.pop();//出队  
    }  
    return 0;  
}  