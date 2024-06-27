#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

// ���������ڵ�
class HuffmanTreeNode {
public:
    char data; // �洢�ַ�
    unsigned freq; // �ַ����ֵ�Ƶ��
    HuffmanTreeNode *left, *right; // ��������ָ��

    HuffmanTreeNode(char data, unsigned freq) {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }
};

// ���ڱȽϵĺ��������ȶ�����Ҫ
struct Compare {
    bool operator()(HuffmanTreeNode* l, HuffmanTreeNode* r) {
        return (l->freq > r->freq);
    }
};

// ��ӡ����������ĺ���
void printCodes(HuffmanTreeNode* root, string str) {
    if (!root) return;

    if (root->data != '$') {
        cout << root->data << ": " << str << "\n";
    }

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// ����������������ӡ����
void HuffmanCodes(char data[], int freq[], int size) {
    HuffmanTreeNode *left, *right, *top;

    // ����һ����С�� & ���������ַ�����С��
    priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare> minHeap;

    for (int i = 0; i < size; ++i) {
        minHeap.push(new HuffmanTreeNode(data[i], freq[i]));
    }

    // �������ж���һ���ڵ�ʱ
    while (minHeap.size() != 1) {
        // ȡ��������С��Ƶ�ʵĽڵ�
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        // ����һ���µ��ڲ��ڵ㣬��Ƶ���������ڵ�Ƶ�ʵĺ͡�'$'�������ַ��������ڲ��ڵ�
        top = new HuffmanTreeNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // ��ӡ�����Ĺ��������ı���
    printCodes(minHeap.top(), "");
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);

    return 0;
}