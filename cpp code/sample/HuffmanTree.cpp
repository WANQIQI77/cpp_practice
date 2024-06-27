#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

// 哈夫曼树节点
class HuffmanTreeNode {
public:
    char data; // 存储字符
    unsigned freq; // 字符出现的频率
    HuffmanTreeNode *left, *right; // 左右子树指针

    HuffmanTreeNode(char data, unsigned freq) {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }
};

// 用于比较的函数，优先队列需要
struct Compare {
    bool operator()(HuffmanTreeNode* l, HuffmanTreeNode* r) {
        return (l->freq > r->freq);
    }
};

// 打印哈夫曼编码的函数
void printCodes(HuffmanTreeNode* root, string str) {
    if (!root) return;

    if (root->data != '$') {
        cout << root->data << ": " << str << "\n";
    }

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// 构建哈夫曼树并打印编码
void HuffmanCodes(char data[], int freq[], int size) {
    HuffmanTreeNode *left, *right, *top;

    // 创建一个最小堆 & 插入所有字符的最小堆
    priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare> minHeap;

    for (int i = 0; i < size; ++i) {
        minHeap.push(new HuffmanTreeNode(data[i], freq[i]));
    }

    // 当堆中有多于一个节点时
    while (minHeap.size() != 1) {
        // 取出两个最小的频率的节点
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        // 创建一个新的内部节点，其频率是两个节点频率的和。'$'是特殊字符，用于内部节点
        top = new HuffmanTreeNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // 打印构建的哈夫曼树的编码
    printCodes(minHeap.top(), "");
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);

    return 0;
}