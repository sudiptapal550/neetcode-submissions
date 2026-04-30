class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        deque<int> dq;
        vector<int> ans;

        while (r < n) {

            while (!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }

            dq.push_back(r);
            if (r >= k-1) {
                ans.push_back(nums[dq.front()]);
            }

            while (!dq.empty() && r - k + 1 >= dq.front()) {
                dq.pop_front();
            }
            r += 1;
        }
        return ans;
                                                 
    }
};          
