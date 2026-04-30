class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        map<int,int> freq;

        for (int num: nums) {
            freq[num] += 1;
        }
        unordered_set<int> visit;

        int ans = 0;
        for (auto m: freq) {
            if (visit.find(m.first) != visit.end()) {
                continue;
            }

            int val = m.first;
            int count = 0;
            while (freq.find(val) != freq.end()) {
                visit.insert(val);
                count += 1;
                val += 1;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
