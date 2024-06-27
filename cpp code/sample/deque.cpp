/*双端队列*/
#include <iostream>
#include <deque>
using namespace std;
int main() {
    // 初始化deque
    deque<int> dq = {1, 2, 3, 4, 5};
    
    // 在末尾添加元素
    dq.push_back(6);
    
    // 在开头添加元素
    dq.push_front(0);
    
    // 访问第一个和最后一个元素
    cout << "First element: " << dq.front() << endl;
    cout << "Last element: " << dq.back() << endl;
    
    // 随机访问
    cout << "Third element: " << dq[2] << endl;
    
    // 使用迭代器遍历deque
    cout << "Elements in deque: ";
    for(deque<int>::iterator it = dq.begin(); it != dq.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // 删除末尾和开头的元素
    dq.pop_back();
    dq.pop_front();
    
    // 修改deque的大小
    dq.resize(3);
    cout << "After resizing to 3 elements: ";
    for(int elem : dq) {
        cout << elem << " ";
    }
    cout << endl;
    
    // 清空deque
    dq.clear();
    cout << "Deque size after clearing: " << dq.size() << endl;
    
    // 检查deque是否为空
    if(dq.empty()) {
        cout << "Deque is empty now." << endl;
    }
    
    return 0;
}