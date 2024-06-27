/*通过vector<int> v来定义一个储存整数的空的vector。当然vector可以存任何类型的数据，比如vector<string> v等等。*/
#include <iostream>    
#include <vector>    
using namespace std;    
int main() {    
    vector<int> v;//定义一个空的vector  
    #include <vector>
    vector<int> vec; // 定义一个空的int类型的vector
    vector<int> vecWithSize(10); // 定义一个初始大小为10的vector
    vector<int> vecWithValues(10, 5); // 定义一个大小为10，初始值都为5的vector
    vector<int> vecCopy = {1, 2, 3, 4, 5}; // 定义并初始化一个vector

    
    // 检查vector是否为空
    if (vec.empty()) {
        cout << "Vector is empty" << std::endl;
    }

    // 获取vector的大小
    cout << "Vector size: " << vec.size() << std::endl;

    // 改变vector的大小
    vec.resize(3); // 现在vec包含{1, 2, 3}

    // 获取vector的容量
    cout << "Vector capacity: " << vec.capacity() << std::endl;

    // 减少vector的容量以匹配其大小
    vec.shrink_to_fit();

    vector<int> vec = {1, 2, 3, 4, 5};

    // 使用范围for循环
    for (int val : vec) {
        cout << val << " ";
    }

    // 使用迭代器
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }

    for (int i = 1; i <= 10; ++i) {    
        v.push_back(i * i); //加入到vector中  
    }    
    for (int i = 0; i < v.size(); ++i) {    
        cout << v[i] << " ";  //访问vecotr的元素  
    }    
    cout << endl;    
    return 0;    
}    