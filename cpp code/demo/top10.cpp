/*
通过priority_queue<int> q来定义一个储存整数的空的priority_queue。当然priority_queue可以存任何类型的数据，比如priority_queue<string> q等等。
*/
#include <iostream>  
#include <queue>  
#include <vector>
#include <queue>
using namespace std;

vector<int> findTop10(vector<int>& nums) {
    priority_queue<int, vector<int>, greater<int>> minHeap; // 最小堆
    for (int num : nums) {
        if (minHeap.size() < 10) { // 如果堆中元素少于10个，直接添加
            minHeap.push(num);
        } else if (num > minHeap.top()) { // 如果当前元素比堆顶元素大，则替换
            minHeap.pop(); // 移除堆顶元素
            minHeap.push(num); // 添加当前元素
        }
    }
    // 将堆中的元素收集到结果vector中
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    return result;
}

int main() {
    vector<int> nums = {21,1,23,1,3,4,5,78,45,6,7,8,9,8,7,6,45,54};
    vector<int> top10 = findTop10(nums);
    for (int num:top10){
        cout << num << " ";
    }

}