#include <iostream>  
#include <string>  
#include <map>  
using namespace std;  
int main() {  
    map<int, int> map1;

    // ʹ���б��ʼ��
    map<int, string> map2 = {{1, "one"}, {2, "two"}, {3, "three"}};

    // ʹ�ò��뷽ʽ��ʼ��
    map<string, int> map3;
    map3["apple"] = 5;
    map3["banana"] = 8;
    map3["cherry"] = 3;

    map<string, int> fruits = {{"apple", 5}, {"banana", 8}, {"cherry", 3}};

    // ʹ���±������[]����Ԫ�أ�����������ڣ���������Ԫ��
    cout << fruits["banana"] << endl; // ���8
    fruits["orange"] = 4; // ������Ԫ��

    // ʹ��at()����Ԫ�أ�������Ƿ���ڣ����������׳�out_of_range�쳣��
    cout << fruits.at("cherry") << endl; // ���3

    map<string, int> fruits = {{"apple", 5}, {"banana", 8}, {"cherry", 3}};

    // ����Ԫ��
    fruits.insert(make_pair("orange", 4));
    fruits["pear"] = 2;

    // �޸�����Ԫ�ص�ֵ
    fruits["apple"] = 10;

    // ɾ��Ԫ��
    fruits.erase("banana"); // ͨ����ɾ��
    

    map<string, int> fruits = {{"apple", 5}, {"banana", 8}, {"cherry", 3}};

    // ʹ�õ�����
    for (map<string, int>::iterator it = fruits.begin(); it != fruits.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    map<string, int> fruits = {{"apple", 5}, {"banana", 8}, {"cherry", 3}};

    // ����Ԫ��
    auto search = fruits.find("apple");
    if (search != fruits.end()) {
        cout << "Found apple, count: " << search->second << endl;
    } else {
        cout << "Apple not found." << endl;
    }

    // ����������map����Ϊ����Ψһ�ģ����ֻ����0��1��
    cout << "Count for banana: " << fruits.count("banana") << endl;


    return 0;  
}  