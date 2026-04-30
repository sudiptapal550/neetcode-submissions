class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int freq[1005] = {0,};
        int n = hand.size();
        if (n % groupSize != 0) return false;
        set<int> mnVal;
        for (int i=0; i < n; i++) {
            freq[hand[i]] += 1;
            mnVal.insert(hand[i]);
        }

        while(!mnVal.empty()) {
            while(!mnVal.empty() && freq[*mnVal.begin()] <= 0) {
                mnVal.erase(mnVal.begin());
            }

            if (mnVal.size() == 0) {
                return true;
            }
            int mnElement = *mnVal.begin();
            for (int i=0; i < groupSize; i++) {
                if (freq[mnElement + i] <= 0) return false;
                freq[mnElement + i] -= 1;
            }
        }

        return true;
    }
};
