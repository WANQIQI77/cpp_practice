/*
ͨ��priority_queue<int> q������һ�����������Ŀյ�priority_queue����Ȼpriority_queue���Դ��κ����͵����ݣ�����priority_queue<string> q�ȵȡ�
*/
#include <iostream>  
#include <queue>  
#include <vector>
#include <queue>
using namespace std;

vector<int> findTop10(vector<int>& nums) {
    priority_queue<int, vector<int>, greater<int>> minHeap; // ��С��
    for (int num : nums) {
        if (minHeap.size() < 10) { // �������Ԫ������10����ֱ�����
            minHeap.push(num);
        } else if (num > minHeap.top()) { // �����ǰԪ�رȶѶ�Ԫ�ش����滻
            minHeap.pop(); // �Ƴ��Ѷ�Ԫ��
            minHeap.push(num); // ��ӵ�ǰԪ��
        }
    }
    // �����е�Ԫ���ռ������vector��
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