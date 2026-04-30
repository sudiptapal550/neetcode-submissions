class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> arr;
        for (int i = 0; i < profits.size(); i++) {
            arr.push_back({capital[i], profits[i]});
        }

        sort(arr.begin(), arr.end());

        priority_queue<pair<int,int>> maxHeap;
        int ind = 0;

        while(k--) {
            while (ind < profits.size() && w >= arr[ind].first) {
                maxHeap.push({arr[ind].second, arr[ind].first});
                ind += 1;
            }
            if (maxHeap.size() == 0) break;

            w += maxHeap.top().first;
            maxHeap.pop();
        }
        return w;
    }
};