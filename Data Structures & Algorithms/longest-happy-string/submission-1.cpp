class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,int>> maxHeap;

        if (a > 0)
            maxHeap.push({a, 0});
        if (b > 0)
            maxHeap.push({b, 1});
        if (c > 0)
            maxHeap.push({c, 2});
        
        string ans = "";
        // aabbaabaa
        // a - 8
        // b - 3
        // aabaabaabaa

        while (!maxHeap.empty()) {
            int count = maxHeap.top().first;
            int val = maxHeap.top().second;
            maxHeap.pop();

            if (ans.length() > 1 && ans.back() == ('a' + val)
                && ans[ans.length() - 2] == ('a' + val)) {
                if (maxHeap.size() == 0) break;

                auto [count2, ch2] = maxHeap.top();

                ans += (char) ('a' + ch2);
                maxHeap.pop();
                if (count2 > 1) {
                    maxHeap.push({count2 - 1, ch2});
                }
                maxHeap.push({count, val});
            } else {
                ans += (char) ('a' + val);
                if (count > 1) {
                    maxHeap.push({count - 1, val});
                }
            }
        }
        return ans;

    }
};