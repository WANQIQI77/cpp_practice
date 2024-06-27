#include <stdio.h>  
#include <string.h>  
#include <math.h>  
#include <stdlib.h>  
#include <time.h>  
#include <algorithm>  
#include <iostream>  
#include <queue>  
#include <stack>  
#include <vector>  
#include <string>  
using namespace std;  
  
struct Student {  
    string name;  
    int grade;  
}stu[1005];  
//从大到小排序  
bool compareDesc(Student a,Student b) {  
    return a.grade > b.grade;  
}  
//从小到大排序  
bool compareAsc(Student a,Student b) {  
    return a.grade < b.grade;  
}  
int main() {  
    int n,order;  
    while(cin>>n) {  
        cin>>order;  
        for(int i=0;i<n;i++) {  
            cin>>stu[i].name>>stu[i].grade;  
        }  
        if(order==0)  
            stable_sort(stu,stu+n,compareDesc);  
        else  
            stable_sort(stu,stu+n,compareAsc);  
        for(int i=0;i<n;i++) {  
            cout<<stu[i].name<<" "<<stu[i].grade<<endl;  
        }  
    }  
    return 0;  
}  