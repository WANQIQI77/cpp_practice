/*
假设表达式中允许包含两种括号:圆括号和方括号。编写一个算法判断表达式中的括号是否正确配对。
输入描述：
由括号构成的字符串，包含”（“、”）“、”[“和”]“。
输出描述：
如果匹配输出YES，否则输出NO。
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isMatched(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

bool areBracketsMatched(const string& expression) {
    stack<char> s;
    for (char ch : expression) {
        if (ch == '(' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == ']') {
            if (s.empty() || !isMatched(s.top(), ch)) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    string expression;
    cin >> expression;
    if (areBracketsMatched(expression)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}