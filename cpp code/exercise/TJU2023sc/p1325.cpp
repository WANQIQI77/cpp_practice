#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int findMaxLength(const vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> maxDeque, minDeque;//�洢ÿ�����������
    int maxLength = 0, left = 0;
    for (int right = 0; right < n; ++right) {  //�����ұ�������
        // �������ֵ����
        //�������飬�����ң��������ֵ����maxDeque����Сֵ����minDeque��
        // �����������Ԫ��ʱ��������������С�ڸ�Ԫ�ص�Ԫ�س��ӣ�Ȼ�󽫸�Ԫ����ӣ�
        while (!maxDeque.empty() && nums[maxDeque.back()] < nums[right]) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(right);

        // ������Сֵ����
        // ��������С��Ԫ��ʱ�������������д��ڸ�Ԫ�ص�Ԫ�س��ӣ�Ȼ�󽫸�Ԫ����ӡ�
        while (!minDeque.empty() && nums[minDeque.back()] > nums[right]) {
            minDeque.pop_back();
        }
        minDeque.push_back(right);
        // ������maxDeque��minDeque�е�Ԫ�ض��ǵ����ġ�

        // �����ǰ�����ڵ����ֵ����Сֵ�Ĳ��k������С����
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