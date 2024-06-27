#include <iostream>
#include <vector>
#include <climits>
using namespace std;
/*С���ĵõ���һ������Ϊn��ֻ����Сд��ĸ�ַ�������ϣ����ȡһ�Σ�ʹ���Ӵ��а���'a'��'z'�������ַ�����һ�Σ�����֪�����ҵ�����̳����Ƕ��١�*/
int findShortestSubString(const string& s) {
    vector<int> charCount(26, 0); // ��¼ÿ���ַ��ĳ��ִ���
    int total = 0; // ��ǰ���ڰ����Ĳ�ͬ�ַ�������
    int minLength = INT_MAX; // ������ַ����ĳ���
    int left = 0; // ���ڵ���߽�

    for (int right = 0; right < s.length(); ++right) {
        if (++charCount[s[right] - 'a'] == 1) { // ����һ���ַ�
            ++total;
        }

        while (total == 26) { // �������Ѱ�������Сд��ĸ
            minLength = min(minLength, right - left + 1);
            if (--charCount[s[left] - 'a'] == 0) { // �Ƴ�һ���ַ�
                --total;
            }
            ++left;
        }
    }

    return minLength == INT_MAX ? -1 : minLength; // ���û���ҵ��򷵻�-1
}

int main() {
    string s;
    cin >> s;
    cout << findShortestSubString(s) << endl;
    return 0;
}