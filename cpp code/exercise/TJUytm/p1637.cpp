#include <iostream>
#include <vector>
#include <climits>
using namespace std;
/*小海棠得到了一个长度为n的只包含小写字母字符串。她希望截取一段，使得子串中包含'a'到'z'中所有字符至少一次，他想知道能找到的最短长度是多少。*/
int findShortestSubString(const string& s) {
    vector<int> charCount(26, 0); // 记录每个字符的出现次数
    int total = 0; // 当前窗口包含的不同字符的数量
    int minLength = INT_MAX; // 最短子字符串的长度
    int left = 0; // 窗口的左边界

    for (int right = 0; right < s.length(); ++right) {
        if (++charCount[s[right] - 'a'] == 1) { // 新增一个字符
            ++total;
        }

        while (total == 26) { // 窗口中已包含所有小写字母
            minLength = min(minLength, right - left + 1);
            if (--charCount[s[left] - 'a'] == 0) { // 移除一个字符
                --total;
            }
            ++left;
        }
    }

    return minLength == INT_MAX ? -1 : minLength; // 如果没有找到则返回-1
}

int main() {
    string s;
    cin >> s;
    cout << findShortestSubString(s) << endl;
    return 0;
}