#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> children[], vector<int>& commands, int node, int command) {
    // ���µ�ǰ�ڵ��������
    commands[node] = command;
    // ������ǰ�ڵ�������ӽڵ㣬���ݹ�ش�������
    for (int child : children[node]) {
        dfs(children, commands, child, command);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> children[n+1]; // �洢ÿ���ڵ���ӽڵ�
        vector<int> commands(n+1, 0); // �洢ÿ���ڵ�������ţ���ʼΪ0

        // �������Ľṹ
        for (int i = 2; i <= n; ++i) {
            int parent;
            cin >> parent;
            children[parent].push_back(i);
        }

        // ִ������
        for (int i = 0; i < k; ++i) {
            int x, y;
            cin >> x >> y;
            dfs(children, commands, x, y);
        }

        // ���ÿ���ڵ��������
        for (int i = 1; i <= n; ++i) {
            cout << commands[i] << " ";
        }
        cout << endl;
    }
    return 0;
}