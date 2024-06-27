/*
题目内容
小C有一批服务器，服务器以算力作为指标。现他需要给服务器分配任务，每个服务器只能承接一个任务，每个任务需要足够算力的服务器才能完成，
即任务所需要的算力x应当小于服务器的算力y。现小C需要为这些服务器分配任务,你需要完成程序，确认最多可以处理任务的数量。

输入描述
多组测试样例，第一行包含一个整数T表示样例个数。
每组样例前两行包含两个整数MN，分别表示服务器数量和任务数量，
第三行包含M个整数，表示服务器的算力，第三行包含N个整数，表示任务所需算力。

输出描述
对于每一组输入，输出一个整数，表示最多可以处理任务的数量。

样例
输入
1
3
2
4 5 6
4 5
输出
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
        // 尝试为每个任务分配服务器
        while (taskIndex < n && serverIndex < m) {
            if (task[taskIndex] <= machine[serverIndex]) {
                // 如果当前服务器能够满足任务的算力需求，则任务完成
                ans++;
                taskIndex++;
                serverIndex++;
            } else {
                // 如果当前服务器不能满足任务的算力需求，尝试下一台服务器
                serverIndex++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}