#include <iostream>  
#include <string>  
#include <map>  
using namespace std;  

struct node{  
    string num;  
    string name;  
    string sex;  
    int age;  
};  
int main(){  
    int n,q;  
    map<string, node> M;//����һ��mapӳ��  
    while(scanf("%d", &n)!=EOF){  
        for(int i=0;i<n;i++){  
            node tmp;  
            cin>>tmp.num>>tmp.name>>tmp.sex>>tmp.age;  
            M[tmp.num] = tmp;//��ѧ��ָ���Ӧ�Ľṹ��  
        }  
        scanf("%d", &q);  
        for(int i=0;i<q;i++){  
            string num;  
            cin>>num;  
            if((M.find(num))!=M.end())//find���� ����Ҳ����򷵻�ĩβ  
                cout<<M[num].num<<" "<<M[num].name<<" "<<M[num].sex<<" "<<M[num].age<<endl;
            else  
                cout<<"No Answer!"<<endl;  
        }  
    }  
    return 0;  
}  