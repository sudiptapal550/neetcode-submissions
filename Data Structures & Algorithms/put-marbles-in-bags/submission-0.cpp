class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> arr;
        int n = weights.size();
        for (int i=1; i < weights.size(); i++) {
            arr.push_back(weights[i-1] + weights[i]);
        }
        long long total = 0;
        sort(arr.begin(), arr.end(), greater<int>());
        for (int i=0; i < arr.size() && i < k-1; i++) {
            total += arr[i];
        }

        k -= 1;
        for (int i=arr.size()-1; i >= 0 && k > 0; i--) {
            total -= arr[i];
            k -= 1;
        }
        return total;

    }
};