#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int findMaxLength(const vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> maxDeque, minDeque;//存储每个数组的索引
    int maxLength = 0, left = 0;
    for (int right = 0; right < n; ++right) {  //从左到右遍历数组
        // 更新最大值队列
        //遍历数组，从左到右，更新最大值队列maxDeque和最小值队列minDeque。
        // 当遇到更大的元素时，将队列中所有小于该元素的元素出队，然后将该元素入队；
        while (!maxDeque.empty() && nums[maxDeque.back()] < nums[right]) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(right);

        // 更新最小值队列
        // 当遇到更小的元素时，将队列中所有大于该元素的元素出队，然后将该元素入队。
        while (!minDeque.empty() && nums[minDeque.back()] > nums[right]) {
            minDeque.pop_back();
        }
        minDeque.push_back(right);
        // 这样，maxDeque和minDeque中的元素都是递增的。

        // 如果当前窗口内的最大值和最小值的差超过k，则缩小窗口
        while (!maxDeque.empty() && !minDeque.empty() && nums[maxDeque.front()] - nums[minDeque.front()] > k) {
            if (maxDeque.front() == left) maxDeque.pop_front();
            if (minDeque.front() == left) minDeque.pop_front();
            left++;
        }
        maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        cout << findMaxLength(nums, k) << endl;
    }
    return 0;
}