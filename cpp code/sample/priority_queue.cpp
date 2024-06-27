#include <iostream>
#include <queue>
#include <vector>
#include <functional> // 包含std::greater

using namespace std;

struct MyObject {
    int value;
    MyObject(int val) : value(val) {}
};
//重载最大堆
bool operator<(const MyObject& a, const MyObject& b) {
    return a.value < b.value; // 对于最大堆
}
//重载最小堆
//定义优先队列的比较关系 和sort的cmp类似  
bool operator < (const MyObject& a, constMyObject& b ){  
    return a.x > b.x;  //逻辑：a.x>b.x,a应该放在b之后
}  

int main() {
    // 最大堆
    priority_queue<int> maxHeap;
    // 最小堆
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // 向堆中添加元素
    for (int num : {1, 5, 3, 4, 2}) {
        maxHeap.push(num);
        minHeap.push(num);
    }
    

    // 访问最大堆和最小堆的顶端元素
    cout << "Max heap top: " << maxHeap.top() << endl; // 输出最大的元素
    cout << "Min heap top: " << minHeap.top() << endl; // 输出最小的元素

    // 移除堆顶元素并展示剩余的顶端元素
    maxHeap.pop();
    minHeap.pop();
    cout << "Max heap top after pop: " << maxHeap.top() << endl;
    cout << "Min heap top after pop: " << minHeap.top() << endl;

    return 0;
}