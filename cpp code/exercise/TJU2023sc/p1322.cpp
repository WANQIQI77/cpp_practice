/*
01�����Ǽ���������õľ���СCϲ����
01������Ѱ��ȫ1���Ӿ���������ɳ��򣬿������һ�����������ȫ1�Ӿ��󣬲�����������ȫ1�Ӿ����а���1�ĸ�����

����
���������������һ�а���������ĸ
mn���ֱ��ʾ������к��У�������
m��ÿ��n���ÿո��������֣���ʾ01�����е�Ԫ�ء�

���
�������һ�����֣���ʾ������ȫ1�Ӿ�����1�ĸ�����
����
5 3
1 0 1
1 1 0
0 1 1
1 0 1
1 1 1
���
3
*/
#include <bits/stdc++.h>
using namespace std;
/*
����һ�����������ͬ����С�Ķ�ά����dp��
dp[i][j]��ʾ��(i, j)λ���ϣ�����������1����������������Լ�����
�������󣬶���ÿ��λ��(i, j)�����a[i][j] == 1����dp[i][j] = dp[i-1][j] + 1�����ڵ�һ�У�dp[0][j] = a[0][j]����
����ÿ��dp[i][j]�����λ�ã�����֪������(i, j)Ϊ�׵����߶ȣ����ǿ�������ɨ�裬�������ľ��������������˵������ÿ��λ��(i, j)��
��������ɨ�裬�ҵ���С��dp[i][k]��k��j��0���������Сֵ��ʾ��ǰ����µ������ܸ߶ȣ�Ȼ��������area = �߶� * ��ȣ�������������
*/
int maximalRectangle(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;
    int max_area = 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) {
                dp[i][j] = i == 0 ? 1 : dp[i-1][j] + 1; // ����߶�

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