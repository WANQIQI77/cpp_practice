
/*通过set<string> country来定义一个储存字符串的空的set。当然set可以存任何类型的数据，比如set<int> s等等。*/
#include <iostream>  
#include <set>  
using namespace std;  
int main() {  
    set<string> country;//定义一个存放string的集合  
    country.insert("China");//插入操作  
    country.insert("America");  
    country.insert("France");  
    set<string>::iterator it;  
    //使用迭代器遍历集合元素  
    for (it = country.begin(); it != country.end(); ++it) {  
        cout << * it  << " ";  
    }  
    cout << endl;  
    country.erase("American");//删除集合内的元素  
    country.erase("England");  
    if (country.count("China")) {//统计元素个数  
        cout << "China in country." << endl;  
    }  
    country.clear();//清空集合  
    return 0;  
}  