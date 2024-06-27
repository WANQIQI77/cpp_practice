/*
������ʽ�����������������:Բ���źͷ����š���дһ���㷨�жϱ��ʽ�е������Ƿ���ȷ��ԡ�
����������
�����Ź��ɵ��ַ���������������������������[���͡�]����
���������
���ƥ�����YES���������NO��
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