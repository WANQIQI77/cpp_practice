#include <iostream>  
#include <stack>  
using namespace std;  
stack<int> S;//定义一个栈  
int main() {  
    S.push(1);//入栈  
    S.push(10);  
    S.push(7);  
    while (!S.empty()) {//当栈不为空  
      cout << S.top() << endl;//输出栈顶元素  
      S.pop();//出栈  
    }  
    return 0;  
}  