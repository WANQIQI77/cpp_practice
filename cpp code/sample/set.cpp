
/*ͨ��set<string> country������һ�������ַ����Ŀյ�set����Ȼset���Դ��κ����͵����ݣ�����set<int> s�ȵȡ�*/
#include <iostream>  
#include <set>  
using namespace std;  
int main() {  
    set<string> country;//����һ�����string�ļ���  
    country.insert("China");//�������  
    country.insert("America");  
    country.insert("France");  
    set<string>::iterator it;  
    //ʹ�õ�������������Ԫ��  
    for (it = country.begin(); it != country.end(); ++it) {  
        cout << * it  << " ";  
    }  
    cout << endl;  
    country.erase("American");//ɾ�������ڵ�Ԫ��  
    country.erase("England");  
    if (country.count("China")) {//ͳ��Ԫ�ظ���  
        cout << "China in country." << endl;  
    }  
    country.clear();//��ռ���  
    return 0;  
}  