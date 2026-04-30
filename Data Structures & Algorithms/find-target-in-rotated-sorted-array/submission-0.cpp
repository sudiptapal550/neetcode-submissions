class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int n = r;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[0] <= nums[mid]) {
                if (nums[mid] > target && nums[0] <= target) {
                    r = mid - 1;
                }
                else l = mid + 1;
            } else {
                 if (nums[mid] < target && nums[n] >= target) {
                    l = mid + 1;
                }
                else r = mid - 1;
            }
        }
        return -1;
    }
};