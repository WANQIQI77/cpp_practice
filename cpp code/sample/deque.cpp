/*˫�˶���*/
#include <iostream>
#include <deque>
using namespace std;
int main() {
    // ��ʼ��deque
    deque<int> dq = {1, 2, 3, 4, 5};
    
    // ��ĩβ���Ԫ��
    dq.push_back(6);
    
    // �ڿ�ͷ���Ԫ��
    dq.push_front(0);
    
    // ���ʵ�һ�������һ��Ԫ��
    cout << "First element: " << dq.front() << endl;
    cout << "Last element: " << dq.back() << endl;
    
    // �������
    cout << "Third element: " << dq[2] << endl;
    
    // ʹ�õ���������deque
    cout << "Elements in deque: ";
    for(deque<int>::iterator it = dq.begin(); it != dq.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // ɾ��ĩβ�Ϳ�ͷ��Ԫ��
    dq.pop_back();
    dq.pop_front();
    
    // �޸�deque�Ĵ�С
    dq.resize(3);
    cout << "After resizing to 3 elements: ";
    for(int elem : dq) {
        cout << elem << " ";
    }
    cout << endl;
    
    // ���deque
    dq.clear();
    cout << "Deque size after clearing: " << dq.size() << endl;
    
    // ���deque�Ƿ�Ϊ��
    if(dq.empty()) {
        cout << "Deque is empty now." << endl;
    }
    
    return 0;
}