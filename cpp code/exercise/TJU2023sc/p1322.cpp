/*
01矩阵是计算机领域常用的矩阵，小C喜欢在
01矩阵中寻找全1的子矩阵，请你完成程序，可以求得一个矩阵中最大全1子矩阵，并输出面积最大的全1子矩阵中包含1的个数。

输入
单组测试样例，第一行包含两个字母
mn，分别表示矩阵的行和列，接下来
m行每行n个用空格分离的数字，表示01矩阵中的元素。

输出
输出包括一个数字，表示面积最大全1子矩阵中1的个数。
输入
5 3
1 0 1
1 1 0
0 1 1
1 0 1
1 1 1
输出
3
*/
#include <bits/stdc++.h>
using namespace std;
/*
创建一个与输入矩阵同样大小的二维数组dp。
dp[i][j]表示在(i, j)位置上，向上连续的1的最大数量（包括自己）。
遍历矩阵，对于每个位置(i, j)，如果a[i][j] == 1，则dp[i][j] = dp[i-1][j] + 1（对于第一行，dp[0][j] = a[0][j]）。
对于每个dp[i][j]非零的位置，我们知道了以(i, j)为底的最大高度，我们可以向左扫描，计算最大的矩形面积。具体来说，对于每个位置(i, j)，
我们向左扫描，找到最小的dp[i][k]（k从j到0），这个最小值表示当前宽度下的最大可能高度，然后计算面积area = 高度 * 宽度，更新最大面积。
*/
int maximalRectangle(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;
    int max_area = 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) {
                dp[i][j] = i == 0 ? 1 : dp[i-1][j] + 1; // 计算高度

                int width = INT_MAX;
                for (int k = j; k >= 0 && matrix[i][k] == 1; --k) {
                    width = min(width, dp[i][k]);
                    max_area = max(max_area, width * (j - k + 1));
                }
            }
        }
    }

    return max_area;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];

    cout << maximalRectangle(matrix) << endl;

    return 0;
}