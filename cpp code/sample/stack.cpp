#include <iostream>  
#include <stack>  
using namespace std;  
stack<int> S;//����һ��ջ  
int main() {  
    S.push(1);//��ջ  
    S.push(10);  
    S.push(7);  
    while (!S.empty()) {//��ջ��Ϊ��  
      cout << S.top() << endl;//���ջ��Ԫ��  
      S.pop();//��ջ  
    }  
    return 0;  
}  