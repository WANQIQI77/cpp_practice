#include <iostream>  
#include <queue>  
using namespace std;  
int main() {  
    queue<int> q;//����һ������  
    q.push(1);//���  
    q.push(2);  
    q.push(3);  
    while (!q.empty()) {//�����в�Ϊ��  
        cout << q.front() << endl;//ȡ������Ԫ��  
        q.pop();//����  
    }  
    return 0;  
}  