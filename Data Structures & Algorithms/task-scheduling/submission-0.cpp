class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,int>> maxHeap;
        int arr[26] = {0,};
        for (int i=0; i < tasks.size(); i++) {
            arr[tasks[i] - 'A'] += 1;
        }

        for (int i=0; i < 26; i++) {
            if (arr[i] != 0) {
                maxHeap.push({arr[i], i});
            }
                
        }

        int time = 0;

        deque<vector<int>> q;

        while (!maxHeap.empty()) {
            int count = maxHeap.top().first;
            char ch = maxHeap.top().second;
            //cout << (char) ('A' + ch) << " " << count << endl;
            maxHeap.pop();

            if (count > 1)
                q.push_back({ch, count - 1, time + n});

            if (maxHeap.size() == 0) {
                if (q.size() > 0) {
                    time = q.front()[2];
                }
            }
            while (!q.empty() && q.front()[2] <= time) {
                maxHeap.push({q.front()[1], q.front()[0]});
                q.pop_front();
            }

            time += 1;
        }
        return time;
    }
};
