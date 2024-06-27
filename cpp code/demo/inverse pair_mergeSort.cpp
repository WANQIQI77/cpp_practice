#include <iostream>
#include <vector>
using namespace std;

// �ϲ����������鲢���������
int merge(vector<int>& nums, int left, int mid, int right, vector<int>& temp) {
    int i = left, j = mid + 1, k = left;
    int inv_count = 0;
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
            inv_count += (mid - i + 1); // nums[i] > nums[j]��˵��nums[i...mid]������nums[j]
        }
    }
    while (i <= mid) {
        temp[k++] = nums[i++];
    }
    while (j <= right) {
        temp[k++] = nums[j++];
    }
    for (int s = left; s <= right; s++) {
        nums[s] = temp[s];
    }
    return inv_count;
}

// �鲢���������ݹ麯��
int mergeSort(vector<int>& nums, int left, int right, vector<int>& temp) {
    if (left >= right) return 0;
    int mid = left + (right - left) / 2;
    int inv_count = 0;
    inv_count += mergeSort(nums, left, mid, temp);
    inv_count += mergeSort(nums, mid + 1, right, temp);
    inv_count += merge(nums, left, mid, right, temp);
    return inv_count;
}

// ���������е������
int reversePairs(vector<int>& nums) {
    vector<int> temp(nums.size());
    return mergeSort(nums, 0, nums.size() - 1, temp);
}

int main() {
    vector<int> nums = {5, 4, 3, 2, 1};
    cout << "Number of reverse pairs: " << reversePairs(nums) << endl;
    return 0;
}