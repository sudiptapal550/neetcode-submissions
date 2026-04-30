class Solution {
public:
    bool isValid(vector<int>& arr, int k) { 
        bool isPossible = false;
        for (char ch = 'A' ; ch <= 'Z'; ch++) {
            int total = 0;
            for (int i = 0; i < arr.size(); i++) {
                if (i != ch - 'A') {
                    total += arr[i];
                }
            }
            isPossible |= (total <= k);
        }
        return isPossible;
    }


    int characterReplacement(string s, int k) {

        int l = 0;
        int r = 0;

        vector<int> arr(26, 0);
        int ans = 0;

        while (r < s.length()) {
            arr[s[r] - 'A'] += 1;

            while (!isValid(arr, k)) {
                arr[s[l++] - 'A'] -= 1;
            }

            if (isValid(arr, k)) {
                ans = max(ans, r - l + 1);
            }

            r += 1;
        }

        return ans;
        
    }
};