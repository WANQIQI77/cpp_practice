#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<pair<int, int>> events;
        for (int i = 0; i < N; ++i) {
            int s, t;
            cin >> s >> t;
            events.push_back({s, 1}); // 会议开始，计数器加1
            events.push_back({t, -1}); // 会议结束，计数器减1
        }
        
        // 按时间顺序排序，如果时间相同，则先处理结束时间
        sort(events.begin(), events.end());
        
        int maxMeetings = 0, currentMeetings = 0;
        for (auto& event : events) {
            currentMeetings += event.second;
            maxMeetings = max(maxMeetings, currentMeetings);
        }
        
        cout << maxMeetings << endl;
    }
    return 0;
}