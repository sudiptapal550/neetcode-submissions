class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        vector<vector<int>> arr;

        for (int i = 0; i < tasks.size(); i++) {
            arr.push_back({tasks[i][0], tasks[i][1], i});
        }
        
        sort(arr.begin(), arr.end());
        vector<int> ans;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        long long time = arr[0][0];

        int index = 0;


        while (index < arr.size() || !minHeap.empty()) {

            while (index < arr.size() && time >= arr[index][0]) {
                minHeap.push({arr[index][1], arr[index][2]});
                index += 1;
            }

            if (minHeap.empty() && index < arr.size()) {
                time = arr[index][0];
            }

            if (!minHeap.empty()) {
                int pTime = minHeap.top().first;
                ans.push_back(minHeap.top().second);
                minHeap.pop();
                time += pTime;
            }
        }
        return ans;
    }
};