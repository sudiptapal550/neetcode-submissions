class Solution {
public:
    bool valid(vector<int>& arr, vector<int>& brr) {
        for (int i = 0; i < 26; i++) {
            if (arr[i] != brr[i]) {
                return false;
            }
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {


        vector<int> arr(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            arr[s1[i] - 'a'] += 1;
        }

        int r = 0;
        int l = 0;
        vector<int> brr(26, 0);
        while (r < s2.length()) {
            brr[s2[r] - 'a'] += 1;

            if (r >= s1.length()) {
                brr[s2[l++] - 'a'] -= 1;
            }

            if (valid(arr, brr)) {
                return true;
            }
            r += 1;
        }

        return false;
        
    }
};