class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();

        int ans = 0;

            int j = m-1;
        // for(int i=0;i<n;i++) if(grid[i][m-1] < 0)
        for(int i=0;i<n;i++){
            if(grid[i][m-1] >= 0) continue;
            while(j>= 0 && grid[i][j] < 0) j--;

            ans += (m-j-1);
        }
        return ans;
    }
};