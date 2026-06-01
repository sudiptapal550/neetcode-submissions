class Solution {
public:
    bool static cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();

        sort(trips.begin(), trips.end(), cmp);
        int currCap = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        for (int i = 0; i < trips.size(); i++) {
            cout << trips[i][1] << " " << trips[i][2] << endl;

            while (!minHeap.empty() && minHeap.top().first <= trips[i][1]) {
                currCap -= minHeap.top().second;
                minHeap.pop();
            }

            if (currCap + trips[i][0] > capacity) {
                return false;
            }
            minHeap.push({trips[i][2], currCap + trips[i][0]});
            currCap += trips[i][0];

        }
        return true;
    }
};