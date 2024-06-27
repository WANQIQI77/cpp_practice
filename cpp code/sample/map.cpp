#include <iostream>  
#include <string>  
#include <map>  
using namespace std;  
int main() {  
    map<int, int> map1;

    // 使用列表初始化
    map<int, string> map2 = {{1, "one"}, {2, "two"}, {3, "three"}};

    // 使用插入方式初始化
    map<string, int> map3;
    map3["apple"] = 5;
    map3["banana"] = 8;
    map3["cherry"] = 3;

    map<string, int> fruits = {{"apple", 5}, {"banana", 8}, {"cherry", 3}};

    // 使用下标操作符[]访问元素，如果键不存在，则会插入新元素
    cout << fruits["banana"] << endl; // 输出8
    fruits["orange"] = 4; // 插入新元素

    // 使用at()访问元素（会检查键是否存在，不存在则抛出out_of_range异常）
    cout << fruits.at("cherry") << endl; // 输出3

    map<string, int> fruits = {{"apple", 5}, {"banana", 8}, {"cherry", 3}};

    // 插入元素
    fruits.insert(make_pair("orange", 4));
    fruits["pear"] = 2;

    // 修改已有元素的值
    fruits["apple"] = 10;

    // 删除元素
    fruits.erase("banana"); // 通过键删除
    

    map<string, int> fruits = {{"apple", 5}, {"banana", 8}, {"cherry", 3}};

    // 使用迭代器
    for (map<string, int>::iterator it = fruits.begin(); it != fruits.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    map<string, int> fruits = {{"apple", 5}, {"banana", 8}, {"cherry", 3}};

    // 查找元素
    auto search = fruits.find("apple");
    if (search != fruits.end()) {
        cout << "Found apple, count: " << search->second << endl;
    } else {
        cout << "Apple not found." << endl;
    }

    // 计数（对于map，因为键是唯一的，结果只能是0或1）
    cout << "Count for banana: " << fruits.count("banana") << endl;


    return 0;  
}  