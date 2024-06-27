/*ͨ��vector<int> v������һ�����������Ŀյ�vector����Ȼvector���Դ��κ����͵����ݣ�����vector<string> v�ȵȡ�*/
#include <iostream>    
#include <vector>    
using namespace std;    
int main() {    
    vector<int> v;//����һ���յ�vector  
    #include <vector>
    vector<int> vec; // ����һ���յ�int���͵�vector
    vector<int> vecWithSize(10); // ����һ����ʼ��СΪ10��vector
    vector<int> vecWithValues(10, 5); // ����һ����СΪ10����ʼֵ��Ϊ5��vector
    vector<int> vecCopy = {1, 2, 3, 4, 5}; // ���岢��ʼ��һ��vector

    
    // ���vector�Ƿ�Ϊ��
    if (vec.empty()) {
        cout << "Vector is empty" << std::endl;
    }

    // ��ȡvector�Ĵ�С
    cout << "Vector size: " << vec.size() << std::endl;

    // �ı�vector�Ĵ�С
    vec.resize(3); // ����vec����{1, 2, 3}

    // ��ȡvector������
    cout << "Vector capacity: " << vec.capacity() << std::endl;

    // ����vector��������ƥ�����С
    vec.shrink_to_fit();

    vector<int> vec = {1, 2, 3, 4, 5};

    // ʹ�÷�Χforѭ��
    for (int val : vec) {
        cout << val << " ";
    }

    // ʹ�õ�����
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }

    for (int i = 1; i <= 10; ++i) {    
        v.push_back(i * i); //���뵽vector��  
    }    
    for (int i = 0; i < v.size(); ++i) {    
        cout << v[i] << " ";  //����vecotr��Ԫ��  
    }    
    cout << endl;    
    return 0;    
}    