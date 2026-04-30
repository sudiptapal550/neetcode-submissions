class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,int>> maxHeap;

        int arr[26] = {0,};
        for (int i=0; i < s.length(); i++) {
            arr[s[i] - 'a'] += 1;
        }

        for (int i=0; i < 26; i++) {
            if (arr[i] > 0)
                maxHeap.push({arr[i], i});
        }

        string ans = "";
        queue<pair<int,int>> q;

        while(!maxHeap.empty() || !q.empty()) {
            int count = -1;
            int val = 0;
            if (maxHeap.size() > 0) {
                count = maxHeap.top().first;
                val = maxHeap.top().second;

                maxHeap.pop();
                if (ans.length() > 0 && ans.back() == 'a' + val) {
                    return "";
                }
                ans += (char) ('a' + val);
            }
            
            if (q.size() >= 1) {
                maxHeap.push(q.front());
                q.pop();
            }

            if (maxHeap.size() == 0) {
                if (q.size() > 0) {
                   maxHeap.push(q.front());
                   q.pop();
                }
            }

            if (count > 1) {
                q.push({count - 1, val});
            }
        }

        return ans;





    }
};