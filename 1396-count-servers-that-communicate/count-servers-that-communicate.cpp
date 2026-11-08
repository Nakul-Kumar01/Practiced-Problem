class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();


        vector<vector<pair<int,int>>>r(n),c(m);
        int t = 0;

        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 1){
                    t++;
                    r[i].push_back({i,j});
                    c[j].push_back({i,j});
                }
            }
        }

        int s = 0;
        for(int i=0;i<n;i++) if(r[i].size() == 1 && c[r[i][0].second].size()==1) s++;
        return t -s;
    }
};