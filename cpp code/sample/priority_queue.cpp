#include <iostream>
#include <queue>
#include <vector>
#include <functional> // ����std::greater

using namespace std;

struct MyObject {
    int value;
    MyObject(int val) : value(val) {}
};
//��������
bool operator<(const MyObject& a, const MyObject& b) {
    return a.value < b.value; // ��������
}
//������С��
//�������ȶ��еıȽϹ�ϵ ��sort��cmp����  
bool operator < (const MyObject& a, constMyObject& b ){  
    return a.x > b.x;  //�߼���a.x>b.x,aӦ�÷���b֮��
}  

int main() {
    // ����
    priority_queue<int> maxHeap;
    // ��С��
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // ��������Ԫ��
    for (int num : {1, 5, 3, 4, 2}) {
        maxHeap.push(num);
        minHeap.push(num);
    }
    

    // �������Ѻ���С�ѵĶ���Ԫ��
    cout << "Max heap top: " << maxHeap.top() << endl; // �������Ԫ��
    cout << "Min heap top: " << minHeap.top() << endl; // �����С��Ԫ��

    // �Ƴ��Ѷ�Ԫ�ز�չʾʣ��Ķ���Ԫ��
    maxHeap.pop();
    minHeap.pop();
    cout << "Max heap top after pop: " << maxHeap.top() << endl;
    cout << "Min heap top after pop: " << minHeap.top() << endl;

    return 0;
}