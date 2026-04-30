class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long total = 0;
        for (int i = 0; i <= limit; i++) {
            int res = n - i;
            if (res < 0 || res > 2*limit) continue;
            total += 2*(min(res, limit) - res/2) + (res % 2 == 0 ? 1 : 0);
           // cout << total << " ";
        }

        return total;

    }
};