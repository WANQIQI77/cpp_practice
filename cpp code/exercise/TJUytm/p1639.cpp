#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> children[], vector<int>& commands, int node, int command) {
    // 更新当前节点的命令编号
    commands[node] = command;
    // 遍历当前节点的所有子节点，并递归地传播命令
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
        vector<int> children[n+1]; // 存储每个节点的子节点
        vector<int> commands(n+1, 0); // 存储每个节点的命令编号，初始为0

        // 构建树的结构
        for (int i = 2; i <= n; ++i) {
            int parent;
            cin >> parent;
            children[parent].push_back(i);
        }

        // 执行命令
        for (int i = 0; i < k; ++i) {
            int x, y;
            cin >> x >> y;
            dfs(children, commands, x, y);
        }

        // 输出每个节点的命令编号
        for (int i = 1; i <= n; ++i) {
            cout << commands[i] << " ";
        }
        cout << endl;
    }
    return 0;
}