class Solution {
public:

    bool dfs(vector<vector<int>>& grid, int r, int c, int mid, vector<vector<int>>& visit) {
        if (r >= grid.size() || r < 0 || c < 0 || c >= grid[0].size() || visit[r][c] == 1 || mid < grid[r][c]) {
            return false;
        }

        if (r == grid.size() - 1 && c == grid[0].size() - 1) return true;
        visit[r][c] = 1;

        return dfs(grid, r + 1, c, mid, visit)
            || dfs(grid, r - 1, c, mid, visit)
            || dfs(grid, r, c + 1, mid, visit)
            || dfs(grid, r , c - 1, mid, visit);
    }

    int swimInWater(vector<vector<int>>& grid) {
        int l = INT_MAX;
        int r = INT_MIN;
        for (auto val: grid) {
            for (auto cell: val) {
                l = min(l, cell);
                r = max(r, cell);
            }
        }

        int m = grid.size();
        int n = grid[0].size();


        while (l <= r) {
            int mid = (l + r) / 2;
            vector<vector<int>> visit(m, vector<int>(n,0));
            if (dfs(grid, 0, 0, mid, visit)) {
                r = mid - 1;
            } else l = mid + 1;
        }

        return l;
        
    }
};
