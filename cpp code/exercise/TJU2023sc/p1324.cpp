/*
��Ŀ����
СC��һ������������������������Ϊָ�ꡣ������Ҫ����������������ÿ��������ֻ�ܳн�һ������ÿ��������Ҫ�㹻�����ķ�����������ɣ�
����������Ҫ������xӦ��С�ڷ�����������y����СC��ҪΪ��Щ��������������,����Ҫ��ɳ���ȷ�������Դ��������������

��������
���������������һ�а���һ������T��ʾ����������
ÿ������ǰ���а�����������MN���ֱ��ʾ����������������������
�����а���M����������ʾ�������������������а���N����������ʾ��������������

�������
����ÿһ�����룬���һ����������ʾ�����Դ��������������

����
����
1
3
2
4 5 6
4 5
���
2

*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int m,n;
        cin >>m>>n;
        vector<int> machine(m);
        vector<int> task(n);
        for(int i=0;i<m;i++){
            cin >>m;
            machine.push_back(m);
        }
        for(int i=0;i<n;i++){
            task.push_back(n);
        }
        sort(machine.begin(),machine.end());
        sort(task.begin(),task.end());
        int ans=0,taskIndex=0,serverIndex=0;
        // ����Ϊÿ��������������
        while (taskIndex < n && serverIndex < m) {
            if (task[taskIndex] <= machine[serverIndex]) {
                // �����ǰ�������ܹ���������������������������
                ans++;
                taskIndex++;
                serverIndex++;
            } else {
                // �����ǰ��������������������������󣬳�����һ̨������
                serverIndex++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}