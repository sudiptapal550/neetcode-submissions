class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            window.insert(nums[i]);

            if (i >= k-1) {
                //cout << window.rbegin() << " ";
                //cout << window.size() << " ";
                ans.push_back(*window.rbegin());
                window.erase(window.find(nums[i - k + 1]));
            }
        }

        return ans;
    }
};
